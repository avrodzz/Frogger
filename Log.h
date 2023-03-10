//
// Created by Alexis Rodriguez on 12/2/20.
//

#ifndef FROGGER_LOG_H
#define FROGGER_LOG_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Frog.h"
#include "Collision.h"

enum LOG_SIZES{
    SMALL,
    MEDIUM,
    LARGE
};


class Log : public sf::Sprite{
public:
    Log(int type = LOG_SIZES::SMALL);
    int getSpriteSize() const;

    void loadAllTextures();

    static const int NUM_OF_TYPES = 3;
    static const int SMALL_LOG_SIZE = 42;
    static const int MEDIUM_LOG_SIZE = 58;
    static const int LARGE_LOG_SIZE = 90;

private:
    static sf::Texture smallLog, mediumLog, largeLog;
    std::string logFileNames[NUM_OF_TYPES] = {"images/smallLog.png","images/mediumLog.png","images/largeLog.png"};
    int spriteSize;
    int speed;

    void setLogSize(int type);
};


#endif //FROGGER_LOG_H
