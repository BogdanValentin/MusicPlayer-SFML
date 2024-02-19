#include "MusicPlayer.hpp"

MusicPlayer::MusicPlayer(int argc, char *argv[]) {
    for(int i = 1; i < argc; i++) {
        Song newSong(argv[i]);
        songList.push_back(newSong);
    }
    currentSong = songList.begin();
    play();
}

// info
std::string MusicPlayer::getCurrentSongTitle() {
    return currentSong->getTitle();
}

int MusicPlayer::getCurrentSongPlayingOffset() {
    return currentSong->getPlayingOffset();
}

int MusicPlayer::getCurrentSongDuration() {
    return currentSong->getDuration();
}

bool MusicPlayer::getLoop() {
    return loop;
}

// controls
void MusicPlayer::play() {
    if(songList.empty()) {
        return;
    }

    currentSong->play();
    currentSong->setVolume(50);
}

void MusicPlayer::stop() {
    currentSong->stop();
}

void MusicPlayer::pause() {
    if(currentSong->getStatus() == sf::Music::Playing) {
        currentSong->pause();
    } else {
        currentSong->unpause();
    }
}

void MusicPlayer::increaseVolume() {
    if(currentSong->getVolume() <= 90) {
        currentSong->setVolume(currentSong->getVolume() + 10);
    }
}

void MusicPlayer::decreaseVolume() {
    if(currentSong->getVolume() >= 10) {
        currentSong->setVolume(currentSong->getVolume() - 10);
    } else { // because of a bug where from 20 it goes to 9.9998 insteam of 10
        currentSong->setVolume(0);
    }
}

void MusicPlayer::seekForward() {
    currentSong->setPlayingOffset(currentSong->getPlayingOffset() + 5);
}

void MusicPlayer::seekBackward() {
    currentSong->setPlayingOffset(currentSong->getPlayingOffset() - 5);
}

void MusicPlayer::next() {
    currentSong->stop();
    if(currentSong == std::prev(songList.end())) {
        if(loop) {
            currentSong = songList.begin();
        } else {
            return;
        }
    } else {
        currentSong++;
    }
    play();
}

void MusicPlayer::previous() {
    currentSong->stop();
    if(currentSong == songList.begin()) {
        if(loop) {
            currentSong = std::prev(songList.end());
        } else {
            play();
            return;
        }
    } else {
        currentSong--;
    }
    play();
}

void MusicPlayer::setLoop(bool newLoop) {
    loop = newLoop;
}

void MusicPlayer::checkAndSwitchToNextSong() {
    if(currentSong->getStatus() == sf::Music::Stopped) {
        if(currentSong == std::prev(songList.end())) {
            if(loop) {
                next();
            } else {
                return;
            }
        } else {
            next();
        }
    }
}