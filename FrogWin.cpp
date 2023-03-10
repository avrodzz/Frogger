//
// Created by Alexis Rodriguez on 12/8/20.
//

#include "FrogWin.h"

FrogWin::FrogWin(const sf::Vector2f& position){
    setPosition(position);
    inBounds = false;
}
void FrogWin::setPosition(const sf::Vector2f& position){
    frogWinBounds.setPosition(position);
    frogWinSprite.setPosition({position.x + X_OFFSET, position.y});
}
void FrogWin::resetInBounds(){
    inBounds = false;
}
bool FrogWin::boundCollision(const sf::Sprite& sprite){
    if(Collision::PixelPerfectTest(sprite,frogWinBounds)){
//        std::cout << "In bounds collision frog win" << std::endl;
        inBounds = true;
        return true;
    }
    return false;
}
void FrogWin::draw(sf::RenderTarget& window,sf::RenderStates states) const{
//    window.draw(frogWinBounds);
    if(inBounds)
        window.draw(frogWinSprite);
}