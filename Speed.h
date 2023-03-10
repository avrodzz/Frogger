//
// Created by Alexis Rodriguez on 12/5/20.
//

#ifndef FROGGER_SPEED_H
#define FROGGER_SPEED_H

#include <iostream>
#include <vector>

enum SPEEDS{
    SLOW,
    MID,
    FAST
};

class Speed {
public:
    Speed();
    int getSpeed() const;
    void setSpeed(int speed);
private:
    std::vector<int> fast = {1,1,1,1,1,1,1,1};
    std::vector<int> mid = {1,0,1,0,1,0,1,0};
    std::vector<int> slow = {1,0,0,1,0,0,1,0};
    mutable int posInSpeed;
    std::vector<int> speedContainerValues;
};


#endif //FROGGER_SPEED_H
