//
// Created by Alexis Rodriguez on 12/1/20.
//

#ifndef FROGGER_FROGGERGAMESTATE_H
#define FROGGER_FROGGERGAMESTATE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "StaticBackground.h"
#include "Grid.h"
#include "Frog.h"
#include "FrogLifeTracker.h"
#include "FroggerSoundManager.h"
#include "YellowCar.h"
#include "Bulldozer.h"
#include "PinkCar.h"
#include "WhiteCar.h"
#include "Truck.h"
#include "Collision.h"
#include "Log.h"
#include "LogLane.h"
#include <vector>
#include "FrogWinGameState.h"
#include "States.h"

class FroggerGameState : public sf::Drawable{
public:
    FroggerGameState();
    void addEvents(sf::RenderTarget& window, sf::Event event);
    void addMusic();
    virtual void draw(sf::RenderTarget& window,sf::RenderStates states) const;
    void update(sf::RenderTarget& window, sf::Event event);
    void run();
    void resumeMusic();
    void pauseMusic();

    STATES getState();
    void setState(STATES gameState);

private:
    StaticBackground background;
    Frog frog;
    FrogLifeTracker lives;
    YellowCar yellowCar;
    Bulldozer bulldozer;
    PinkCar pinkCar;
    WhiteCar whiteCar;
    Truck truck;
    FroggerSoundManager sounds;

    std::vector<LogLane> logLanes;
//    Grid grid;
//    sf::Clock timeRun;
    FrogWinGameState win;
    STATES gameState;
};


#endif //FROGGER_FROGGERGAMESTATE_H
