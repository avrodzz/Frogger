//
// Created by Alexis Rodriguez on 12/10/20.
//

#include "StaticSplashBackground.h"

StaticSplashBackground::StaticSplashBackground(){
    title.setPosition({TITLE_POS_X,TITLE_POS_Y});
    splashView.setSize(ORIGINAL_SCREEN_WIDTH,ORIGINAL_SCREEN_HEIGHT);
    splashView.setCenter(ORIGINAL_SCREEN_WIDTH / 2, ORIGINAL_SCREEN_HEIGHT / 2);


    if(!font.loadFromFile("font/ARCADECLASSIC.TTF")){
        std::cout << "font/ARCADECLASSIC.TTF was not able to load into font" << std::endl;
        exit(1);
    }
    text.setFont(font);
    text.setString("GAME  OVER");
    text.setFillColor({255,0,0});
    text.setCharacterSize(20);
    text.setPosition({splashView.getCenter().x - text.getGlobalBounds().width / 2,splashView.getCenter().y - text.getGlobalBounds().height / 2 * 4});
}
void StaticSplashBackground::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(background);
    window.draw(title);
    window.draw(text);
}
sf::View StaticSplashBackground::getView() const{
    return splashView;
}