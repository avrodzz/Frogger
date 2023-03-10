//
// Created by Alexis Rodriguez on 12/4/20.
//

#ifndef FROGGER_LOGLANE_H
#define FROGGER_LOGLANE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Log.h"
#include "Direction.h"
#include "Speed.h"
#include "Collision.h"
#include "Frog.h"
#include <list>
#include "LinkedList.h"

enum LANE_NUMBERS{
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE
};


class LogLane : public sf::Drawable{
public:
    LogLane(int laneNumber = LANE_NUMBERS::ONE, int direction = DIRECTION::LEFT, int speed = SPEEDS::MID);
    void move();
    void setSpeed(int speed);
    void addEvents(sf::RenderTarget& window, Frog& frog);
    void draw(sf::RenderTarget& window,sf::RenderStates states) const;

    static const int START_Y_POS = 99;
    static const int NUM_OF_RAND_LANES = 3;
    static const int LANE_Y_OFFSET = 16;

    static const int X_POS = 241;
    static const int LEFT_X_BOUNDS = 240;
    static const int RIGHT_X_BOUNDS = 22;
    static const int SPEED = 1; // Full Speed = 1
private:
    std::list<Log> logLane;
    int laneNumber = 0;
    int direction = 0;
    float y_pos;

    void moveLeft();
    void moveRight();

    Speed logSpeed;
    int count = 0;
    int speedOffset = 0;
};


#endif //FROGGER_LOGLANE_H
