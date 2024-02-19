#include "MusicPlayer.hpp"

MusicPlayer::MusicPlayer(int argc, char *argv[]) {
    for(int i = 1; i < argc; i++) {
        Song newSong(argv[i]);
        songQueue.push(newSong);
    }

    play();
}

// info
std::string MusicPlayer::getCurrentSongTitle() {
    return songQueue.front().getTitle();
}

int MusicPlayer::getCurrentSongPlayingOffset() {
    return songQueue.front().getPlayingOffset();
}

int MusicPlayer::getCurrentSongDuration() {
    return songQueue.front().getDuration();
}

// controls
void MusicPlayer::play() {
    if(songQueue.empty()) {
        return;
    }

    songQueue.front().play();
    songQueue.front().setVolume(50);
}

void MusicPlayer::stop() {
    if(songQueue.empty()) {
        return;
    }

    songQueue.front().stop();
}

void MusicPlayer::pause() {
    if(songQueue.empty()) {
        return;
    }
    if(songQueue.front().getStatus() == sf::Music::Playing) {
        songQueue.front().pause();
    } else {
        songQueue.front().unpause();
    }
}

void MusicPlayer::increaseVolume() {
    if(songQueue.empty()) {
        return;
    }
    if(songQueue.front().getVolume() <= 90) {
        songQueue.front().setVolume(songQueue.front().getVolume() + 10);
    }
}

void MusicPlayer::decreaseVolume() {
    if(songQueue.empty()) {
        return;
    }
    if(songQueue.front().getVolume() >= 10) {
        songQueue.front().setVolume(songQueue.front().getVolume() - 10);
    } else { // because of a bug where from 20 it goes to 9.9998 insteam of 10
        songQueue.front().setVolume(0);
    }
}

void MusicPlayer::seekForward() {
    if(songQueue.empty()) {
        return;
    }
    songQueue.front().setPlayingOffset(songQueue.front().getPlayingOffset() + 5);
}

void MusicPlayer::seekBackward() {
    if(songQueue.empty()) {
        return;
    }
    songQueue.front().setPlayingOffset(songQueue.front().getPlayingOffset() - 5);
}
