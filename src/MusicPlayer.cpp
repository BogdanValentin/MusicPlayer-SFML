#include "MusicPlayer.hpp"

void MusicPlayer::playSong(const std::string &filename) {
    if(!musicStream.openFromFile(filename)) {
        exit(1);
    }

    musicStream.play();
    musicStream.setVolume(50);
}

void MusicPlayer::stopSong() {
    musicStream.stop();
}

void MusicPlayer::pauseSong() {
    if(musicStream.getStatus() == sf::Music::Playing) {
        musicStream.pause();
    } else {
        musicStream.play();
    }
}

void MusicPlayer::increaseVolume() {
    if(musicStream.getVolume() <= 90) {
        musicStream.setVolume(musicStream.getVolume() + 10);
    }
}

void MusicPlayer::decreaseVolume() {
    if(musicStream.getVolume() >= 10) {
        musicStream.setVolume(musicStream.getVolume() - 10);
    } else {
        musicStream.setVolume(0);
    }
}

void MusicPlayer::printVolume() {
    std::cout << "Volume: " << musicStream.getVolume() << std::endl;
}