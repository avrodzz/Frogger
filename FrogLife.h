//
// Created by Alexis Rodriguez on 12/1/20.
//

#ifndef FROGGER_FROGLIFE_H
#define FROGGER_FROGLIFE_H

#include <iostream>
#include <SFML/Graphics.hpp>

class FrogLife : public sf::Sprite{
public:
    FrogLife();
    FrogLife(sf::Texture* frogLifeTexture);

    // Start FrogLife Position
    const static int START_X_POS = 1, START_Y_POS = 225;

    // FrogLife
    const static int FROG_LIFE_WIDTH = 8;

private:
    sf::Texture* frogLifeTexture;
};


#endif //FROGGER_FROGLIFE_H
