# Terminal Music Player

A terminal-based music player written in C++ using SFML audio.

## Introduction

This project is a minimalistic music player that operates in the terminal and utilizes the SFML audio library for playback. It allows users to play their favorite music directly from the command line.

## Features

- **Playlist Management:**
  - Open one or more songs to create a playlist.

- **Playback Controls:**
  - Play/Pause/Stop: Toggle between playing, pausing or stopping the current track.
  - Seek Forward/Backward: Navigate within the track timeline.

- **Audio Control:**
  - Change Volume: Adjust the volume level during playback.
  
- **Navigation:**
  - Next/Previous: Move to the next or previous track in the playlist.

- **Looping:**
  - Enable/Disable Looping: Repeat the current playlist.

## Requirements

- C++11 or later
- SFML library

## Installation

1. Install SFML:

    ```bash
    sudo apt-get install libsfml-dev # On Debian/Ubuntu
    ```

    For other systems, please refer to the [SFML installation guide](https://www.sfml-dev.org/tutorials/2.5/start-linux.php).

2. Clone the repository:

    ```bash
    git clone https://github.com/BogdanValentin/MusicPlayer-SFML.git
    ```

3. Build the project:

    ```bash
    cd MusicPlayer-SFML
    g++ src/*.cpp -o MusicPlayer -lsfml-system -lsfml-audio
    ```

## Usage

1. Navigate to the project directory:

    ```bash
    cd MusicPlayer-SFML
    ```

2. Run the executable with one or more music files as arguments:

    ```bash
    ./MusicPlayer path/to/your/song1.ogg path/to/your/song2.ogg ...
    ```

3. Use the following controls:

    **space:** Play / Pause song  
    **s:** Stop song  
    **+:** Increase volume  
    **-:** Decrease volume  
    **.:** Seek forward  (5s)  
    **,:** Seek backward (5s)  
    **n:** Next song  
    **b:** Previous song  
    **l:** Toggle loop  
    **q:** Quit

## License
This project is licensed under the MIT License.
