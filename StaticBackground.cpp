//
// Created by Alexis Rodriguez on 11/28/20.
//

#include "StaticBackground.h"

StaticBackground::StaticBackground(){
    title.setPosition({TITLE_POS_X,TITLE_POS_Y});
    gShrub.setPosition({0,24});
    pShrubTop.setPosition({0,112});
    pShrubBottom.setPosition({0,208});

    view.setSize(ORIGINAL_SCREEN_WIDTH,ORIGINAL_SCREEN_HEIGHT);
    view.setCenter(ORIGINAL_SCREEN_WIDTH / 2, ORIGINAL_SCREEN_HEIGHT / 2);
}
void StaticBackground::draw(sf::RenderTarget& window,sf::RenderStates states) const{
    window.draw(background);
    window.draw(title);
    window.draw(gShrub);
    window.draw(pShrubTop);
    window.draw(pShrubBottom);
}
sf::View StaticBackground::getView() const{
    return view;
}