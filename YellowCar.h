//
// Created by Alexis Rodriguez on 11/28/20.
//

#ifndef FROGGER_YELLOWCAR_H
#define FROGGER_YELLOWCAR_H

#include "Vehicle.h"

class YellowCar : public Vehicle{
public:
    YellowCar();
    void moveVehicleRight();
    void moveVehicleLeft();

    constexpr static const float YELLOW_CAR_SPEED = 1;
    static const int YELLOW_CAR_SIZE = 16;
    static const int Y_POS = 207;
};


#endif //FROGGER_YELLOWCAR_H
