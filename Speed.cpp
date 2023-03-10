//
// Created by Alexis Rodriguez on 12/5/20.
//

#include "Speed.h"

Speed::Speed(){
    setSpeed(SPEEDS::MID);
}
int Speed::getSpeed() const{
    int value = speedContainerValues[posInSpeed];
    posInSpeed++;
    if(posInSpeed >= speedContainerValues.size())
        posInSpeed = 0;
    return value;
}
void Speed::setSpeed(int speed){
    posInSpeed = 0;
    switch(speed){
        case SPEEDS::SLOW:
            speedContainerValues = slow;
            break;
        case SPEEDS::MID:
            speedContainerValues = mid;
            break;
        case SPEEDS::FAST:
            speedContainerValues = fast;
            break;
    }
}