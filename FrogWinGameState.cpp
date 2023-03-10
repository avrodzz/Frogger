//
// Created by Alexis Rodriguez on 12/8/20.
//

#include "FrogWinGameState.h"

FrogWinGameState::FrogWinGameState(){
    for(int i = 0; i < NUM_OF_FROG_WINS; i++){
        FrogWin temp({static_cast<float>(FROG_WIN_POS_X + (FROG_WIN_X_OFFSET * i)), FROG_WIN_POS_Y});
        frogWins.push_back(temp);
    }
}
bool FrogWinGameState::checkAllForCollision(const sf::Sprite& sprite){
    for(int i = 0; i < NUM_OF_FROG_WINS; i++){
        if(frogWins[i].boundCollision(sprite)){
            win.push_back(true);
            return true;
        }
    }
    return false;
}
bool FrogWinGameState::won() const{
    return win.size() >= NUM_OF_FROG_WINS;
}
void FrogWinGameState::draw(sf::RenderTarget& window,sf::RenderStates states) const{
    for(int i  = 0; i < NUM_OF_FROG_WINS; i++){
        window.draw(frogWins[i]);
    }
}
void FrogWinGameState::reset(){
    for(int i = 0; i < NUM_OF_FROG_WINS; i++){
        frogWins[i].resetInBounds();
    }
    win.clear();
}