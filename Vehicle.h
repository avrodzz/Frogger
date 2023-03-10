//
// Created by Alexis Rodriguez on 11/28/20.
//

#ifndef FROGGER_VEHICLE_H
#define FROGGER_VEHICLE_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Vehicle : public sf::Sprite{
public:
    Vehicle();
    Vehicle(const std::string& filePath);

    virtual void moveVehicleRight(int spriteSize = 0, float speed = 0.0);
    virtual void moveVehicleLeft(int spriteSize = 0, float speed = 0.0);

    static const int X_POS = 32;
    static const int X_BOUNDS = 240;

    float getSpeed() const{return speed;};
    int getSpriteSize() const{return spriteSize;};
    void setSpeed(float speed){this->speed = speed;};
    void setSpriteSize(int spriteSize){this->spriteSize = spriteSize;};

private:
    sf::Texture vehicleTexture;
    float speed;
    int spriteSize;
};


#endif //FROGGER_VEHICLE_H
