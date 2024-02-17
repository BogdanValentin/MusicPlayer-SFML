#include "Interface.hpp"

Interface::Interface(MusicPlayer *newMusicPlayer) : musicPlayer(newMusicPlayer) {}

void Interface::showPanel() {
    std::cout << "Now playing: " <<  musicPlayer->getSongTitle() << std::endl;
    std::cout << "Time: " << std::fixed << std::setprecision(2) << musicPlayer->getTime() << std::endl;
}

void Interface::showMenu() {
    std::cout << "<space>: Play / Pause song" << std::endl;
    std::cout << "s: Stop song" << std::endl;
    std::cout << "+: Increase volume" << std::endl;
    std::cout << "-: Decrease volume" << std::endl;
    std::cout << ".: Seek forward  (5s)" << std::endl;
    std::cout << ",: Seek backward (5s)" << std::endl;
    std::cout << "q: Quit" << std::endl;
    std::cout << std::endl;
}