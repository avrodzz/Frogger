//
// Created by Alexis Rodriguez on 12/8/20.
//

#ifndef FROGGER_FROGWINGAMESTATE_H
#define FROGGER_FROGWINGAMESTATE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "FrogWin.h"

class FrogWinGameState : public sf::Drawable{
public:
    FrogWinGameState();
    static const int FROG_WIN_POS_X = 15;
    static const int FROG_WIN_POS_Y = 31;
    static const int FROG_WIN_X_OFFSET = 48;
    static const int NUM_OF_FROG_WINS = 5;

    bool checkAllForCollision(const sf::Sprite& sprite);
    bool won() const;
    virtual void draw(sf::RenderTarget& window,sf::RenderStates states) const;

    void reset();

private:
    std::vector<FrogWin> frogWins;
    std::vector<bool> win;
};


#endif //FROGGER_FROGWINGAMESTATE_H
