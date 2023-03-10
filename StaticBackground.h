//
// Created by Alexis Rodriguez on 11/28/20.
//

#ifndef FROGGER_STATICBACKGROUND_H
#define FROGGER_STATICBACKGROUND_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "GameTitle.h"
#include "GreenShrub.h"
#include "PurpleShrub.h"

class StaticBackground : public sf::Drawable, public sf::Transformable {
public:
    StaticBackground();

    // Draws out all the static (non-moving) components featured in the game
    virtual void draw(sf::RenderTarget& window,sf::RenderStates states) const;

    //DOES NOT WORK FIGURE OUT WHY
    //void setScale(float x, float y);
    sf::View getView() const;

    sf::Sprite getGShrub() const{return gShrub;};

    static const int ORIGINAL_SCREEN_WIDTH = 240;
    static const int ORIGINAL_SCREEN_HEIGHT = 256;

    // Title Position
    static const int TITLE_POS_X = 42;
    static const int TITLE_POS_Y = 0;

private:
    Background background;
    GameTitle title;
    GreenShrub gShrub;
    PurpleShrub pShrubTop, pShrubBottom;
    sf::View view;
};


#endif //FROGGER_STATICBACKGROUND_H
