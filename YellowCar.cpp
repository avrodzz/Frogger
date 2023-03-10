//
// Created by Alexis Rodriguez on 11/28/20.
//

#include "YellowCar.h"

YellowCar::YellowCar() : Vehicle("images/yellowCar.png"){
    rotate(180);
    setPosition({Vehicle::X_POS, Y_POS});
    setSpriteSize(YELLOW_CAR_SIZE);
    setSpeed(YELLOW_CAR_SPEED);
}
void YellowCar::moveVehicleRight(){
    Vehicle::moveVehicleRight(getSpriteSize(),getSpeed());
}
void YellowCar::moveVehicleLeft(){
    Vehicle::moveVehicleLeft(getSpriteSize(),getSpeed());
}