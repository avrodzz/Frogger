//
// Created by Alexis Rodriguez on 11/28/20.
//

#include "GameTitle.h"

GameTitle::GameTitle() : GameTitle("images/froggerTitle.png"){

}
GameTitle::GameTitle(std::string filePath){
    if(!title.loadFromFile(filePath)){
        std::cout << filePath << " could not load into title" << std::endl;
        exit(1);
    }
    setTexture(title);
}