//
// Created by Alexis Rodriguez on 12/6/20.
//

#ifndef FROGGER_FROGGER_H
#define FROGGER_FROGGER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "States.h"
#include "FroggerGameState.h"
#include "SplashScreenGameState.h"
#include "MusicStates.h"

class Frogger{
public:
    Frogger();
    void setState(STATES state);
    void addEvents(sf::RenderTarget& window, sf::Event event);
    void update(sf::RenderTarget& window, sf::Event event);
    void run();
    const int SCALE = 4;
    const int ORIGINAL_GAME_SIZE_WIDTH = 240;
    const int ORIGINAL_GAME_SIZE_HEIGHT = 256;

private:
    FroggerGameState froggerGame;
    SplashScreenGameState splashScreen;
    STATES currentState;
    STATES lastState;
    MUSIC_STATES currentMusicState;
    MUSIC_STATES lastMusicState;
};


#endif //FROGGER_FROGGER_H
