//
// Created by Alexis Rodriguez on 12/8/20.
//

#ifndef FROGGER_FROGWINSPRITE_H
#define FROGGER_FROGWINSPRITE_H

#include <iostream>
#include <SFML/Graphics.hpp>

class FrogWinSprite : public sf::Sprite{
public:
    FrogWinSprite();

private:
    static sf::Texture frogWin;
    static bool textureLoaded;
    void setFrogWinTexture();
};


#endif //FROGGER_FROGWINSPRITE_H
