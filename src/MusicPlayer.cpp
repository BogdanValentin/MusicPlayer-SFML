#include "MusicPlayer.hpp"

MusicPlayer::MusicPlayer(const std::string &filename) {
    songTitle = filename;
    int position = songTitle.find_last_of('/');
    songTitle = songTitle.substr(position + 1);
}

std::string MusicPlayer::getSongTitle() {
    return songTitle;
}

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
    } else { // because of a bug where from 20 it goes to 9.9998 insteam of 10
        musicStream.setVolume(0);
    }
}

double MusicPlayer::getTime() {
    double time = musicStream.getPlayingOffset().asSeconds();
    int minutes = time / 60;
    double seconds = time - (minutes * 60);
    return minutes + seconds / 100;
}