//
// Created by Alexis Rodriguez on 12/10/20.
//

#ifndef FROGGER_STATICSPLASHBACKGROUND_H
#define FROGGER_STATICSPLASHBACKGROUND_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "GameTitle.h"


class StaticSplashBackground : public sf::Drawable{
public:
    StaticSplashBackground();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    sf::View getView() const;

    static const int ORIGINAL_SCREEN_WIDTH = 240;
    static const int ORIGINAL_SCREEN_HEIGHT = 256;

    // Title Position
    static const int TITLE_POS_X = 42;
    static const int TITLE_POS_Y = 0;


private:
    Background background;
    GameTitle title;
    sf::View splashView;
    sf::Font font;
    sf::Text text;
};


#endif //FROGGER_STATICSPLASHBACKGROUND_H
