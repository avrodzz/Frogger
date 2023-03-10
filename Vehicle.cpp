//
// Created by Alexis Rodriguez on 11/28/20.
//

#include "Vehicle.h"

Vehicle::Vehicle() : Vehicle("images/yellowCar.png"){
    speed = 0.0;
    spriteSize = 0;
}
Vehicle::Vehicle(const std::string& filePath){
    if(!vehicleTexture.loadFromFile(filePath)){
        std::cout << filePath << " could not be loaded into vehicleTexture" << std::endl;
        exit(1);
    }
    setTexture(vehicleTexture);
}
void Vehicle::moveVehicleRight(int spriteSize, float speed){
    if(getPosition().x < X_BOUNDS)
        move(speed,0);
    if(getPosition().x >= X_BOUNDS)
        setPosition({static_cast<float>(spriteSize * -1),getPosition().y});
}
void Vehicle::moveVehicleLeft(int spriteSize, float speed){
    int x_pos = -(spriteSize);
    if(getPosition().x > x_pos)
        move(speed * -1, 0);
    if(getPosition().x <= x_pos)
        setPosition({static_cast<float>(X_BOUNDS + spriteSize),getPosition().y});
    std::vector<int> v;
}