#pragma once

#include <string>

#include <SFML/Audio.hpp>

class Song {
    std::string title;
    sf::Music *musicStream;
public:
    Song(const std::string &filename);

    // info
    std::string getTitle();
    sf::Music::Status getStatus();
    float getVolume();
    int getPlayingOffset();
    int getDuration();

    // controls
    void play();
    void stop();
    void pause();
    void unpause();
    void setVolume(float volume);
    void setPlayingOffset(int seconds);
};