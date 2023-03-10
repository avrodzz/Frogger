//
// Created by Alexis Rodriguez on 12/8/20.
//

#ifndef FROGGER_SPLASHSCREENGAMESTATE_H
#define FROGGER_SPLASHSCREENGAMESTATE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "StaticSplashBackground.h"
#include "FroggerSoundManager.h"
#include "States.h"

class SplashScreenGameState : public sf::Drawable{
public:
    SplashScreenGameState();
    void addMusic();
    void addEvents(sf::RenderTarget& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window,sf::RenderStates states) const;
    void update(sf::RenderTarget& window, sf::Event event);
    void run();

    STATES getState();
    void setState(STATES gameState);

    void resumeMusic();
    void pauseMusic();

private:
    StaticSplashBackground background;
    FroggerSoundManager sounds;
    STATES gameState;
};


#endif //FROGGER_SPLASHSCREENGAMESTATE_H
