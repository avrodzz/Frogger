//
// Created by Alexis Rodriguez on 11/28/20.
//

#include "Bulldozer.h"

Bulldozer::Bulldozer() : Vehicle("images/bulldozer.png"){
    setPosition({Vehicle::X_POS, Y_POS});
    setSpriteSize(BULLDOZER_SIZE);
    setSpeed(BULLDOZER_SPEED);
}
void Bulldozer::moveVehicleRight(){
    Vehicle::moveVehicleRight(getSpriteSize(),getSpeed());
}
void Bulldozer::moveVehicleLeft(){
    Vehicle::moveVehicleLeft(getSpriteSize(),getSpeed());
}