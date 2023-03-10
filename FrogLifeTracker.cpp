//
// Created by Alexis Rodriguez on 12/1/20.
//

#include "FrogLifeTracker.h"

FrogLifeTracker::FrogLifeTracker(){
    frogLifeTexture = new sf::Texture;
    if(!frogLifeTexture->loadFromFile("images/frogLife.png")){
        std::cout << "images/frogLife.png" << " could not be loaded into frogLifeTexture" << std::endl;
        exit(1);
    }

    livesLeft = Frog::MAX_NUM_LIVES;
    init();
}
void FrogLifeTracker::init(){
    sf::Vector2f temp;
    for(int i = 0; i < livesLeft; i++){
        FrogLife tempFrogLife(frogLifeTexture);
        temp.x = tempFrogLife.getPosition().x + FrogLife::FROG_LIFE_WIDTH * i;
        temp.y = tempFrogLife.getPosition().y;
        tempFrogLife.setPosition({temp.x,temp.y});
        lifeTracker.push(tempFrogLife);
    }
}
void FrogLifeTracker::loseALife(){
    if(livesLeft > 0){
        FrogLife life = lifeTracker.pop();
        livesLeft--;
    }
}
void FrogLifeTracker::resetFrogLifeTracker(){
    int tempSize = lifeTracker.size();
    for(int i = 0; i < tempSize; i++){
        lifeTracker.pop();
    }
    livesLeft = Frog::MAX_NUM_LIVES;
    init();
}
void FrogLifeTracker::draw(sf::RenderTarget& window,sf::RenderStates states) const{
    int size = lifeTracker.size();
    Stack<FrogLife> tempStack = lifeTracker;
    for(int i = 0; i < size; i++){
        FrogLife temp = tempStack.pop();
        window.draw(temp);
    }
}