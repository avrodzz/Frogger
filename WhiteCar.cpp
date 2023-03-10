//
// Created by Alexis Rodriguez on 11/28/20.
//

#include "WhiteCar.h"

WhiteCar::WhiteCar() : Vehicle("images/whiteCar.png"){
    setPosition({Vehicle::X_POS, Y_POS});
    setSpeed(WHITE_CAR_SPEED);
    setSpriteSize(WHITE_CAR_SIZE);
}
void WhiteCar::moveVehicleRight(){
    Vehicle::moveVehicleRight(getSpriteSize(),getSpeed());
}
void WhiteCar::moveVehicleLeft(){
    Vehicle::moveVehicleLeft(getSpriteSize(),getSpeed());
}