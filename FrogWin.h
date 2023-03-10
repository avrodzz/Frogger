//
// Created by Alexis Rodriguez on 12/8/20.
//

#ifndef FROGGER_FROGWIN_H
#define FROGGER_FROGWIN_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "FrogWinSprite.h"
#include "FrogWinBounds.h"
#include "Collision.h"
#include "Frog.h"

class FrogWin : public sf::Drawable{
public:
    FrogWin(const sf::Vector2f& position = {0,0});
    void setPosition(const sf::Vector2f& position);
    void resetInBounds();
    bool boundCollision(const sf::Sprite& sprite);
    virtual void draw(sf::RenderTarget& window,sf::RenderStates states) const;

    static const int X_OFFSET = 1;

private:
    FrogWinSprite frogWinSprite;
    FrogWinBounds frogWinBounds;
    bool inBounds;
};


#endif //FROGGER_FROGWIN_H
