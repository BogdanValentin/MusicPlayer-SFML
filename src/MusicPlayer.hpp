#pragma once

#include <iostream>
#include <SFML/Audio.hpp>

class MusicPlayer {
    sf::Music musicStream;
public:
    void printVolume();

    void playSong(const std::string &filename);
    void stopSong();
    void pauseSong();
    void increaseVolume();
    void decreaseVolume();
};