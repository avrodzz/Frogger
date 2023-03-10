//
// Created by Alexis Rodriguez on 11/28/20.
//

#include "PinkCar.h"

PinkCar::PinkCar() : Vehicle("images/pinkCar.png"){
    setPosition({Vehicle::X_POS, Y_POS});
    setSpriteSize(PINK_CAR_SIZE);
    setSpeed(PINK_CAR_SPEED);
}
void PinkCar::moveVehicleRight(){
    Vehicle::moveVehicleRight(getSpriteSize(),getSpeed());
}
void PinkCar::moveVehicleLeft(){
    Vehicle::moveVehicleLeft(getSpriteSize(),getSpeed());
}