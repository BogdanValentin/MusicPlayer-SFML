#pragma once

#include <queue>

#include "Song.hpp"

class MusicPlayer {
    std::queue<Song> songQueue;
public:
    MusicPlayer(int argc, char *argv[]);

    // info
    std::string getCurrentSongTitle();
    int getCurrentSongPlayingOffset();
    int getCurrentSongDuration();

    // controls
    void play();
    void stop();
    void pause();
    void increaseVolume();
    void decreaseVolume();
    void seekForward();
    void seekBackward();
};