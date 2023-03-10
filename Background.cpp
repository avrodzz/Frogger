//
// Created by Alexis Rodriguez on 11/28/20.
//

#include "Background.h"

Background::Background(){
    top.setSize({TOP_WIDTH, TOP_HEIGHT});
    top.setFillColor(sf::Color(topColor[0],topColor[1],topColor[2]));

    bottom.setSize({BOTTOM_WIDTH, BOTTOM_HEIGHT});
    bottom.setFillColor(sf::Color(bottomColor[0], bottomColor[1], bottomColor[2]));
    bottom.setPosition({BOTTOM_POS_X, BOTTOM_POS_Y});
}
void Background::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(top);
    window.draw(bottom);
}