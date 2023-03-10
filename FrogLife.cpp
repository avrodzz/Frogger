//
// Created by Alexis Rodriguez on 12/1/20.
//

#include "FrogLife.h"

FrogLife::FrogLife() {

}
FrogLife::FrogLife(sf::Texture* frogLifeTexture) : frogLifeTexture(frogLifeTexture){
    setTexture(*frogLifeTexture);
    setPosition({START_X_POS,START_Y_POS});
}