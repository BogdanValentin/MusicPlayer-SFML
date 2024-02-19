#pragma once

#include <iostream>
#include <iomanip>

#include "MusicPlayer.hpp"

class Interface {
    MusicPlayer *musicPlayer;

    double convertSecondsToTime(double seconds);
public:
    Interface(MusicPlayer *newMusicPlayer);
    void showPanel();
    void showMenu();
};