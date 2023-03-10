//
// Created by Alexis Rodriguez on 12/1/20.
//

#ifndef FROGGER_FROGGERSOUNDMANAGER_H
#define FROGGER_FROGGERSOUNDMANAGER_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "MusicStates.h"

class FroggerSoundManager {
public:
    FroggerSoundManager();
    void playHop();
    void playSquash();
    void playPlunk();
    void playCoinIn();
    void playSplashScreenMusic();
    void playArcadeMusic();
    void playGameoverMusic();
    void reset();
    void pause();
    void resume();
    MUSIC_STATES getState() const;
    void setState(MUSIC_STATES currentMusicState);

    static const int NUM_OF_SOUNDS = 3;
    static const int MUSIC_VOLUME = 20;
    static const int SOUND_VOLUME = 40;

private:
    void play(sf::Music* music);
    void play(const sf::SoundBuffer& soundBuffer);

    sf::Music splashScreen, arcade, gameOver;
    sf::SoundBuffer hop, squashed, plunk, coinIn;

    sf::Music* musicPtr;
    std::vector<sf::Sound> froggerSounds;
    sf::Sound sound;
    MUSIC_STATES currentMusicState;
};


#endif //FROGGER_FROGGERSOUNDMANAGER_H
