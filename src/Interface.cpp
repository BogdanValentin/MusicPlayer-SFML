#include "Interface.hpp"

Interface::Interface(MusicPlayer *newMusicPlayer) : musicPlayer(newMusicPlayer) {}

void Interface::showPanel() {
    std::cout << "Now playing: " <<  musicPlayer->getSongTitle() << std::endl;
}

void Interface::showMenu() {
    std::cout << "p: Play / Pause song" << std::endl;
    std::cout << "s: Stop song"  << std::endl;
    std::cout << "+: Increase volume" << std::endl;
    std::cout << "-: Decrease volume" << std::endl;
    std::cout << "q: Quit"       << std::endl;
    std::cout << std::endl;
    std::cout << "Command: ";
}