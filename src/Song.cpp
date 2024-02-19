#include "Song.hpp"

Song::Song(const std::string &filename) {
    title = filename;
    int index = title.find_last_of("/");
    title = title.substr(index + 1);

    musicStream = new sf::Music();
    if(!musicStream->openFromFile(filename)) {
        exit(1);
    }
}

// info
std::string Song::getTitle() {
    return title;
}

sf::Music::Status Song::getStatus() {
    return musicStream->getStatus();
}

float Song::getVolume() {
    return musicStream->getVolume();
}

int Song::getPlayingOffset() {
    return musicStream->getPlayingOffset().asSeconds();
}

int Song::getDuration() {
    return musicStream->getDuration().asSeconds();
}

// controls
void Song::play() {
    musicStream->play();
    musicStream->setVolume(50);
}

void Song::stop() {
    musicStream->stop();
}

void Song::pause() {
    musicStream->pause();
}

void Song::unpause() {
    musicStream->play();
}

void Song::setVolume(float volume) {
    // normalise volume
    if(volume < 0) {
        volume = 0;
    } else if(volume > 100) {
        volume = 100;
    }
    musicStream->setVolume(volume);
}

void Song::setPlayingOffset(int seconds) {
    if(seconds < 0) {
        seconds = 0;
    } else if(seconds > getDuration()) {
        seconds = 0;
        musicStream->stop();
    }
    musicStream->setPlayingOffset(sf::seconds(seconds));
}
