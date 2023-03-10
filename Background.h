//
// Created by Alexis Rodriguez on 11/28/20.
//

#ifndef FROGGER_BACKGROUND_H
#define FROGGER_BACKGROUND_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Background : public sf::Drawable, public sf::Transformable {
public:
    Background();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    static const int NUM_OF_COLORS = 3;
    static const int TOP_WIDTH = 240, TOP_HEIGHT = 127;
    static const int BOTTOM_WIDTH = 240, BOTTOM_HEIGHT = 129;
    static const int BOTTOM_POS_X = 0, BOTTOM_POS_Y = 126;

private:
    sf::RectangleShape top, bottom;
    int topColor[NUM_OF_COLORS] = {0,0,71};
    int bottomColor[NUM_OF_COLORS] = {0,0,0};
};


#endif //FROGGER_BACKGROUND_H
