//
// Created by Alexis Rodriguez on 11/28/20.
//

#ifndef FROGGER_TRUCK_H
#define FROGGER_TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle{
public:
    Truck();
    void moveVehicleRight();
    void moveVehicleLeft();

    constexpr static float TRUCK_SPEED = 1;
    static const int TRUCK_SIZE = 27;
    static const int Y_POS = 131;
};


#endif //FROGGER_TRUCK_H
