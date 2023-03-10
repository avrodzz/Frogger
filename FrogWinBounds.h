//
// Created by Alexis Rodriguez on 12/8/20.
//

#ifndef FROGGER_FROGWINBOUNDS_H
#define FROGGER_FROGWINBOUNDS_H

#include <iostream>
#include <SFML/Graphics.hpp>

class FrogWinBounds : public sf::Sprite{
public:
    FrogWinBounds();

private:
    static sf::Texture frogWinBounds;
    static bool textureLoaded;
    void setFrogWinBoundsTexture();
};


#endif //FROGGER_FROGWINBOUNDS_H
