#pragma once

#include <iostream>
#include <SFML/Audio.hpp>

class MusicPlayer {
    std::string songTitle;
    sf::Music musicStream;

    double convertSecondsToTime(double seconds);
public:
    MusicPlayer(const std::string &filename);

    // info
    std::string getSongTitle();
    double getTime();
    double getDuration();

    // controls
    void playSong(const std::string &filename);
    void stopSong();
    void pauseSong();
    void increaseVolume();
    void decreaseVolume();
    void seekForward();
    void seekBackward();
};