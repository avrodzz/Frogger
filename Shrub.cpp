//
// Created by Alexis Rodriguez on 11/28/20.
//

#include "Shrub.h"

Shrub::Shrub(){

}
Shrub::Shrub(std::string filePath){
    if(!shrub.loadFromFile(filePath)){
        std::cout << filePath << " could not be loaded into shrub" << std::endl;
    }
    setTexture(shrub);
}