#include "MusicPlayer.hpp"

void MusicPlayer::playSong(const std::string &filename) {
    if(!musicStream.openFromFile(filename)) {
        exit(1);
    }

    musicStream.play();
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
