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

void MusicPlayer::seekForward() {
    if(musicStream.getStatus() == sf::Music::Stopped) {
        return;
    }
    if(musicStream.getPlayingOffset() + sf::seconds(5) < musicStream.getDuration()) {
        musicStream.setPlayingOffset(musicStream.getPlayingOffset() + sf::seconds(5));
    } else {
        musicStream.stop();
    }
}

void MusicPlayer::seekBackward() {
    if(musicStream.getPlayingOffset() - sf::seconds(5) > sf::seconds(0)) {
        musicStream.setPlayingOffset(musicStream.getPlayingOffset() - sf::seconds(5));
    } else {
        musicStream.setPlayingOffset(sf::seconds(0));
    }
}

double MusicPlayer::getTime() {
    return convertSecondsToTime(musicStream.getPlayingOffset().asSeconds());
}

double MusicPlayer::getDuration() {
    return convertSecondsToTime(musicStream.getDuration().asSeconds());
}

double MusicPlayer::convertSecondsToTime(double seconds) {
    int m = seconds / 60;
    double s = seconds - (m * 60);
    return m + s / 100;
}
