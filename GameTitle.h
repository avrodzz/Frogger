//
// Created by Alexis Rodriguez on 11/28/20.
//

#ifndef FROGGER_GAMETITLE_H
#define FROGGER_GAMETITLE_H

#include <iostream>
#include <SFML/Graphics.hpp>

class GameTitle : public sf::Sprite{
public:
    GameTitle();
    GameTitle(std::string filePath);

private:
    sf::Texture title;
};


#endif //FROGGER_GAMETITLE_H
