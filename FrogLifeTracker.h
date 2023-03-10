//
// Created by Alexis Rodriguez on 12/1/20.
//

#ifndef FROGGER_FROGLIFETRACKER_H
#define FROGGER_FROGLIFETRACKER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Frog.h"
#include "FrogLife.h"
#include "Stack.h"

class FrogLifeTracker : public sf::Drawable, public sf::Transformable{
public:
    FrogLifeTracker();
    void init();
    void loseALife();
    void resetFrogLifeTracker();
    virtual void draw(sf::RenderTarget& window,sf::RenderStates states) const;

    int getLivesLeft() const{return livesLeft;};
    void setNumOfLives(const int& numOfLives){livesLeft = numOfLives;};
    bool noLivesLeft() const{return livesLeft == 0;};


private:
    Stack<FrogLife> lifeTracker;
    sf::Texture* frogLifeTexture;
    int livesLeft;
};


#endif //FROGGER_FROGLIFETRACKER_H