#include <iostream>

#include "MusicPlayer.hpp"
#include "Interface.hpp"

int main(int argc, char *argv[]) {
    if(argc != 2) {
        std::cout << "Error: " << "Invalid number of arguments" << std::endl;
        std::cout << "Usage: " << "MusicPlayer " << "<filename>" << std::endl;
        return 1;
    }

    MusicPlayer musicPlayer;
    musicPlayer.playSong(argv[1]);

    while(true) {
        sf::sleep(sf::milliseconds(100)); // avoid 100% CPU usage

        std::cout << "\033[2J\033[1;1H";
        Interface::showMenu();
        
        char input = getchar();
        if(input == 'q') {
            musicPlayer.stopSong();
            break;
        }
        if(input == 'p') {
            musicPlayer.pauseSong();
        }
        if(input == 's') {
            musicPlayer.stopSong();
        }
        if(input == '+') {
            musicPlayer.increaseVolume();
        }
        if(input == '-') {
            musicPlayer.decreaseVolume();
        }
    }
    
    return 0;
}