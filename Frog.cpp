//
// Created by Alexis Rodriguez on 11/28/20.
//

#include "Frog.h"

Frog::Frog() : Frog("images/frog.png"){

}
Frog::Frog(const std::string& filePath){
    if(!frogTexture.loadFromFile(filePath)){
        std::cout << filePath << " could not be loaded into frogTexture" << std::endl;
        exit(1);
    }
    frogRect.top = TOP;
    frogRect.left = LEFT;
    frogRect.width = WIDTH;
    frogRect.height = HEIGHT;
    setTexture(frogTexture);
    setTextureRect(frogRect);

    init();
}
sf::FloatRect Frog::getGlobalBounds(){
    return sf::Sprite::getGlobalBounds();
}
void Frog::init(){
    setPosition({START_X_POS, START_Y_POS});
}
void Frog::deathReset(){
    frogSounds.playSquash();
    init();
}
void Frog::frogWinReset(){
    init();
}
void Frog::addEvents(sf::RenderTarget& window, sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
           moveUp();
        }
        if (event.key.code == sf::Keyboard::Down) {
            moveDown();
        }
        if (event.key.code == sf::Keyboard::Left) {
            moveLeft();
        }
        if (event.key.code == sf::Keyboard::Right) {
            moveRight();
        }
    }
}
void Frog::moveUp(){
    if (getPosition().y > LOWEST_TOP_BOUNDS) {
        frogSounds.playHop();
        setPosition({getPosition().x, getPosition().y - PIXEL_SIZE});
    }
}
void Frog::moveDown(){
    if (getPosition().y < HIGHEST_BOTTOM_BOUNDS) {
        frogSounds.playHop();
        setPosition({getPosition().x, getPosition().y + PIXEL_SIZE});
    }
}
void Frog::moveLeft(){
    if (getPosition().x > LOWEST_LEFT_BOUNDS) {
        frogSounds.playHop();
        setPosition({getPosition().x - PIXEL_SIZE, getPosition().y});
    }
}
void Frog::moveRight(){
    if (getPosition().x < HIGHEST_RIGHT_BOUNDS) {
        frogSounds.playHop();
        setPosition({getPosition().x + PIXEL_SIZE, getPosition().y});
    }
}
void Frog::onLogMovement(int direction, int offset){
    if(direction == DIRECTION::LEFT){
        move(offset * -1,0);
    }
    if(direction == DIRECTION::RIGHT){
        move(offset, 0);
    }
}