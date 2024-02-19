#include <iostream>
#include <thread>
#include <future>
#include <termios.h>
#include <unistd.h>

#include "MusicPlayer.hpp"
#include "Interface.hpp"

void setNonCanonicalMode() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Error: " << "Invalid number of arguments" << std::endl;
        std::cout << "Usage: " << "MusicPlayer " << "<filename>" << std::endl;
        return 1;
    }

    MusicPlayer musicPlayer(argc, argv);


    setNonCanonicalMode();

    auto inputFuture = std::async(std::launch::async, [&musicPlayer]() {
        char input;
        while (true) {
            input = getchar();
            if (input == 'q') {
                musicPlayer.stop();
                break;
            }
            if (input == ' ') {
                musicPlayer.pause();
            }
            if (input == 's') {
                musicPlayer.stop();
            }
            if (input == '+') {
                musicPlayer.increaseVolume();
            }
            if (input == '-') {
                musicPlayer.decreaseVolume();
            }
            if (input == '.') {
                musicPlayer.seekForward();
            }
            if (input == ',') {
                musicPlayer.seekBackward();
            }
        }
        return input;
    });

    while (inputFuture.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout) {
        std::cout << "\033[2J\033[1;1H";
        Interface interface(&musicPlayer);
        interface.showPanel();
        std::cout << std::endl;
        interface.showMenu();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    musicPlayer.stop();  // Stop the song when 'q' is pressed
    char userInput = inputFuture.get();

    // Restore terminal settings
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);

    return 0;
}