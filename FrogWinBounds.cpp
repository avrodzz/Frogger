//
// Created by Alexis Rodriguez on 12/8/20.
//

#include "FrogWinBounds.h"

sf::Texture FrogWinBounds::frogWinBounds;
bool FrogWinBounds::textureLoaded = false;

FrogWinBounds::FrogWinBounds(){
    if(!textureLoaded){
        setFrogWinBoundsTexture();
    }
    setTexture(frogWinBounds);
}
void FrogWinBounds::setFrogWinBoundsTexture(){
    if(!frogWinBounds.loadFromFile("images/frogWinBounds.png")){
        std::cout << "images/frogWinBounds.png could not be loaded into frogWinBounds" << std::endl;
        exit(1);
    }
    textureLoaded = true;
}