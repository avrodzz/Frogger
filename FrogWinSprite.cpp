//
// Created by Alexis Rodriguez on 12/8/20.
//

#include "FrogWinSprite.h"

sf::Texture FrogWinSprite::frogWin;
bool FrogWinSprite::textureLoaded = false;

FrogWinSprite::FrogWinSprite(){
    if(!textureLoaded){
        setFrogWinTexture();
    }
    setTexture(frogWin);
}
void FrogWinSprite::setFrogWinTexture(){
    if(!frogWin.loadFromFile("images/frogWin.png")){
        std::cout << "images/frogWin.png could not be loaded into frogWin" << std::endl;
        exit(1);
    }
    textureLoaded = true;
}