#pragma once

#include <iostream>
#include <SFML/Audio.hpp>

class MusicPlayer {
    std::string songTitle;
    sf::Music musicStream;
public:
    MusicPlayer(const std::string &filename);
    std::string getSongTitle();
    void playSong(const std::string &filename);
    void stopSong();
    void pauseSong();
    void increaseVolume();
    void decreaseVolume();
    double getTime();
};