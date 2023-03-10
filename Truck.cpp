//
// Created by Alexis Rodriguez on 11/28/20.
//

#include "Truck.h"

Truck::Truck() : Vehicle("images/truck.png"){
    setPosition({Vehicle::X_POS, Y_POS});
    setSpriteSize(TRUCK_SIZE);
    setSpeed(TRUCK_SPEED);
}
void Truck::moveVehicleRight(){
    Vehicle::moveVehicleRight(getSpriteSize(),getSpeed());
}
void Truck::moveVehicleLeft(){
    Vehicle::moveVehicleLeft(getSpriteSize(),getSpeed());
}