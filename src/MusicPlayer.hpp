#include <SFML/Audio.hpp>

class MusicPlayer {
    sf::Music musicStream;
public:
    void playSong(const std::string &filename);
    void stopSong();
    void pauseSong();
};