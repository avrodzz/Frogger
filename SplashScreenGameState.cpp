//
// Created by Alexis Rodriguez on 12/8/20.
//

#include "SplashScreenGameState.h"

SplashScreenGameState::SplashScreenGameState(){
    gameState = STATES::SPLASH_SCREEN;
}
void SplashScreenGameState::addMusic(){
    sounds.playGameoverMusic();
}
void SplashScreenGameState::addEvents(sf::RenderTarget& window, sf::Event event){
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::C) {
            sounds.playCoinIn();
            setState(STATES::FROGGER_GAME);
        }
    }
}
void SplashScreenGameState::draw(sf::RenderTarget& window,sf::RenderStates states) const{
    window.setView(background.getView());
    window.draw(background);
}
void SplashScreenGameState::update(sf::RenderTarget& window, sf::Event event){

}
void SplashScreenGameState::run(){

}
STATES SplashScreenGameState::getState(){
    return gameState;
}
void SplashScreenGameState::setState(STATES gameState){
    this->gameState = gameState;
}
void SplashScreenGameState::resumeMusic(){
    sounds.resume();
}
void SplashScreenGameState::pauseMusic(){
    sounds.pause();
}