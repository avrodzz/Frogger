//
// Created by Alexis Rodriguez on 11/28/20.
//

#ifndef FROGGER_SHRUB_H
#define FROGGER_SHRUB_H

#include <iostream>
#include <SFML/Graphics.hpp>


class Shrub : public sf::Sprite{
public:
    Shrub();
    Shrub(std::string filePath);

private:
    sf::Texture shrub;
};


#endif //FROGGER_SHRUB_H
