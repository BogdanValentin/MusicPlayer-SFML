#pragma once

#include <iostream>

#include "MusicPlayer.hpp"

class Interface {
    MusicPlayer *musicPlayer;
public:
    Interface(MusicPlayer *newMusicPlayer);
    void showPanel();
    void showMenu();
};