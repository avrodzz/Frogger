//
// Created by Alexis Rodriguez on 11/28/20.
//

#ifndef FROGGER_WHITECAR_H
#define FROGGER_WHITECAR_H

#include "Vehicle.h"

class WhiteCar : public Vehicle{
public:
    WhiteCar();
    void moveVehicleRight();
    void moveVehicleLeft();

    constexpr static float WHITE_CAR_SPEED = 1;
    static const int WHITE_CAR_SIZE = 16;
    static const int Y_POS = 145;
};


#endif //FROGGER_WHITECAR_H
