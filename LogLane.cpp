//
// Created by Alexis Rodriguez on 12/4/20.
//

#include "LogLane.h"

LogLane::LogLane(int laneNumber, int direction, int speed){
    this->direction = direction;
    setSpeed(speed);
    y_pos = START_Y_POS - (LANE_Y_OFFSET * laneNumber);
    Log s1(LOG_SIZES::SMALL),
        s2(LOG_SIZES::LARGE),
        s3(LOG_SIZES::SMALL);

    s1.setPosition({3, y_pos});
    s2.setPosition({67,y_pos});
    s3.setPosition({179, y_pos});

    logLane.push_back(s1);
    logLane.push_back(s2);
    logLane.push_back(s3);
}
void LogLane::move(){
    if(logSpeed.getSpeed() == 1){
        speedOffset = 1;
        if(direction == DIRECTION::LEFT)
            moveLeft();
        if(direction == DIRECTION::RIGHT)
            moveRight();
    }
    else{
        speedOffset = 0;
    }
}
void LogLane::setSpeed(int speed){
    logSpeed.setSpeed(speed);
}
void LogLane::addEvents(sf::RenderTarget& window, Frog& frog) {
    for (Log& log : logLane) {
        if (Collision::PixelPerfectTest(log, frog)) {
            frog.onLogMovement(direction,speedOffset);
        }
    }
}
void LogLane::draw(sf::RenderTarget& window,sf::RenderStates states) const{
    for(const Log& log : logLane){
        window.draw(log);
    }
}
void LogLane::moveRight(){
    for(Log& log : logLane) {
        if (log.getPosition().x < LEFT_X_BOUNDS){
            log.move(SPEED, 0);
        }
    }
    if(logLane.back().getPosition().x > LEFT_X_BOUNDS)
        logLane.pop_back();
    if(logLane.front().getPosition().x == RIGHT_X_BOUNDS){
        Log temp(rand() % NUM_OF_RAND_LANES);
        temp.setPosition({static_cast<float>(-(temp.getSpriteSize())),y_pos});
        logLane.push_front(temp);
    }
}
void LogLane::moveLeft(){
    bool offScreen = false;

    for(Log& log : logLane){
        int x_pos = -(log.getSpriteSize());
        if(log.getPosition().x > x_pos){
            log.move(SPEED * -1, 0);
        }
        else
            offScreen = true;
    }
    if(offScreen)
        logLane.pop_front();

    if(logLane.back().getPosition().x + logLane.back().getSpriteSize() + RIGHT_X_BOUNDS == LEFT_X_BOUNDS){
        Log temp(rand() % NUM_OF_RAND_LANES);
        temp.setPosition({LEFT_X_BOUNDS,y_pos});
        logLane.push_back(temp);
    }
}