//
// Created by Alexis Rodriguez on 12/1/20.
//

#include "FroggerGameState.h"

FroggerGameState::FroggerGameState() {
    gameState = STATES::FROGGER_GAME;
    LogLane l1(LANE_NUMBERS::ONE, DIRECTION::RIGHT, SPEEDS::SLOW),
            l2(LANE_NUMBERS::TWO, DIRECTION::LEFT,SPEEDS::FAST),
            l3(LANE_NUMBERS::THREE, DIRECTION::RIGHT, SPEEDS::SLOW),
            l4(LANE_NUMBERS::FOUR, DIRECTION::LEFT, SPEEDS::MID);
//    logLanes.push_back(l1);
    logLanes.push_back(l2);
//    logLanes.push_back(l3);
    logLanes.push_back(l4);
}
void FroggerGameState::addEvents(sf::RenderTarget& window, sf::Event event){
    frog.addEvents(window, event);
}
void FroggerGameState::addMusic(){
    if(!lives.noLivesLeft())
        sounds.playArcadeMusic();
    if(lives.noLivesLeft())
        sounds.playGameoverMusic();
}
void FroggerGameState::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.setView(background.getView());
    window.draw(background);
    window.draw(yellowCar);
    window.draw(bulldozer);
    window.draw(pinkCar);
    window.draw(whiteCar);
    window.draw(truck);
    window.draw(lives);
    window.draw(win);

    for(int i = 0; i < logLanes.size(); i++){
        window.draw(logLanes[i]);
    }
    window.draw(frog);
//    window.draw(grid);
}
void FroggerGameState::update(sf::RenderTarget& window, sf::Event event){
    if(Collision::PixelPerfectTest(frog,yellowCar) || Collision::PixelPerfectTest(frog,bulldozer)
       || Collision::PixelPerfectTest(frog,pinkCar) || Collision::PixelPerfectTest(frog,whiteCar)
       || Collision::PixelPerfectTest(frog,truck) || Collision::PixelPerfectTest(frog,background.getGShrub())){
        frog.deathReset();
        lives.loseALife();
    }

    if (win.checkAllForCollision(frog))
        frog.frogWinReset();
    if(win.won()){
        std::cout << "YOU WON!" << std::endl;
        win.reset();
        lives.resetFrogLifeTracker();
        setState(STATES::SPLASH_SCREEN);
    }
    else if(lives.noLivesLeft() and !win.won()){
        std::cout << "YOU LOSE!" << std::endl;
        win.reset();
        lives.resetFrogLifeTracker();
        setState(STATES::SPLASH_SCREEN);
    }

    for(int i = 0; i < logLanes.size(); i++){
        logLanes[i].addEvents(window,frog);
    }

    if(frog.getPosition().x <= 0 || frog.getPosition().x  == 240 - Frog::FROG_SIZE){
        frog.deathReset();
        lives.loseALife();
    }
}
void FroggerGameState::run(){
    yellowCar.moveVehicleLeft();
    bulldozer.moveVehicleRight();
    pinkCar.moveVehicleLeft();
    whiteCar.moveVehicleRight();
    truck.moveVehicleLeft();

    for(int i = 0; i < logLanes.size(); i++){
        logLanes[i].move();
    }
}
void FroggerGameState::resumeMusic(){
    sounds.resume();
}
void FroggerGameState::pauseMusic(){
    sounds.pause();
}
STATES FroggerGameState::getState(){
    return gameState;
}
void FroggerGameState::setState(STATES gameState){
    this->gameState = gameState;
}