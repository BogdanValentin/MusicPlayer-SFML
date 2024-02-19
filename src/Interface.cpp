#include "Interface.hpp"

Interface::Interface(MusicPlayer *newMusicPlayer) : musicPlayer(newMusicPlayer) {}

double Interface::convertSecondsToTime(double seconds) {
    int m = seconds / 60;
    double s = (seconds - (m * 60)) / 100;
    return m + s;
}

void Interface::showPanel() {
    std::cout << "Now playing: " <<  musicPlayer->getCurrentSongTitle() << std::endl;
    std::cout << "Time: " << std::fixed << std::setprecision(2) 
              << convertSecondsToTime(musicPlayer->getCurrentSongPlayingOffset()) << " out of "
              << convertSecondsToTime(musicPlayer->getCurrentSongDuration()) << std::endl;
    std::cout << "Looping? " << std::boolalpha << musicPlayer->getLoop() << std::endl;
}

void Interface::showMenu() {
    std::cout << "<space>: Play / Pause song" << std::endl;
    std::cout << "s: Stop song" << std::endl;
    std::cout << "+: Increase volume" << std::endl;
    std::cout << "-: Decrease volume" << std::endl;
    std::cout << ".: Seek forward  (5s)" << std::endl;
    std::cout << ",: Seek backward (5s)" << std::endl;
    std::cout << "n: Next song" << std::endl;
    std::cout << "b: Previous song" << std::endl;
    std::cout << "l: Toggle loop" << std::endl;
    std::cout << "q: Quit" << std::endl;
    std::cout << std::endl;
}