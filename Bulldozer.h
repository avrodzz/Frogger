//
// Created by Alexis Rodriguez on 11/28/20.
//

#ifndef FROGGER_BULLDOZER_H
#define FROGGER_BULLDOZER_H

#include "Vehicle.h"

class Bulldozer : public Vehicle{
public:
    Bulldozer();
    void moveVehicleRight();
    void moveVehicleLeft();

    constexpr static float BULLDOZER_SPEED = 1;
    static const int BULLDOZER_SIZE = 14;

    static const int Y_POS = 178;
};


#endif //FROGGER_BULLDOZER_H
