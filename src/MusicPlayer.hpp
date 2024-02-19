#pragma once

#include <list>

#include "Song.hpp"

class MusicPlayer {
    std::list<Song> songList;
    std::list<Song>::iterator currentSong;
    bool loop = true;
public:
    MusicPlayer(int argc, char *argv[]);

    // info
    std::string getCurrentSongTitle();
    int getCurrentSongPlayingOffset();
    int getCurrentSongDuration();
    bool getLoop();

    // controls
    void play();
    void stop();
    void pause();
    void increaseVolume();
    void decreaseVolume();
    void seekForward();
    void seekBackward();
    void next();
    void previous();
    void setLoop(bool newLoop);
    void checkAndSwitchToNextSong();
};