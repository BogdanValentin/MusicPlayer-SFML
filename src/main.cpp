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
    t.c_lflag &= ~(ICANON | ECHO);  // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Error: " << "Invalid number of arguments" << std::endl;
        std::cout << "Usage: " << "MusicPlayer " << "<filename>" << std::endl;
        return 1;
    }

    // Set non-canonical mode for input
    setNonCanonicalMode();

    MusicPlayer musicPlayer(argv[1]);
    musicPlayer.playSong(argv[1]);

    auto inputFuture = std::async(std::launch::async, [&musicPlayer]() {
        char input;
        while (true) {
            input = getchar();
            if (input == 'q') {
                musicPlayer.stopSong();
                break;
            }
            if (input == 'p') {
                musicPlayer.pauseSong();
            }
            if (input == 's') {
                musicPlayer.stopSong();
            }
            if (input == '+') {
                musicPlayer.increaseVolume();
            }
            if (input == '-') {
                musicPlayer.decreaseVolume();
            }
        }
        return input;
    });

    while (inputFuture.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout) {
        // Update and display interface here
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        std::cout << "\033[2J\033[1;1H";
        Interface interface(&musicPlayer);
        interface.showPanel();
        std::cout << std::endl;
        interface.showMenu();
    }

    musicPlayer.stopSong();  // Stop the song when 'q' is pressed
    char userInput = inputFuture.get();  // Retrieve user input
    // Handle user input if needed

    // Restore terminal settings
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);

    return 0;
}