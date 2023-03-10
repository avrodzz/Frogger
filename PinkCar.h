//
// Created by Alexis Rodriguez on 11/28/20.
//

#ifndef FROGGER_PINKCAR_H
#define FROGGER_PINKCAR_H

#include "Vehicle.h"

class PinkCar : public Vehicle{
public:
    PinkCar();
    void moveVehicleRight();
    void moveVehicleLeft();

    constexpr static float PINK_CAR_SPEED = 1;
    static const int PINK_CAR_SIZE = 15;
    static const int Y_POS = 163;
};


#endif //FROGGER_PINKCAR_H
