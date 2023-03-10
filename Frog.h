//
// Created by Alexis Rodriguez on 11/28/20.
//

#ifndef FROGGER_FROG_H
#define FROGGER_FROG_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "FroggerSoundManager.h"
#include <cmath>
#include "Speed.h"
#include "Direction.h"

class Frog : public sf::Sprite{
public:
    Frog();
    Frog(const std::string& filePath);
    void init();
    void deathReset();
    void frogWinReset();
    sf::FloatRect getGlobalBounds();
//    void move(int direction, int speed);
    void onLogMovement(int direction, int offset);

    // FROG IN SPRITE SHEET
    static const int TOP = 4, LEFT = 2, WIDTH = 12, HEIGHT = 9;

    // Start Frog Position
    const static int START_X_POS = 146, START_Y_POS = 212;
    void addEvents(sf::RenderTarget& window, sf::Event event);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    // Controls how far the frog can travel off of the screen
    static const int LOWEST_TOP_BOUNDS = 36;
    static const int LOWEST_LEFT_BOUNDS = 4;
    static const int HIGHEST_RIGHT_BOUNDS = 224;
    static const int HIGHEST_BOTTOM_BOUNDS = 212;
    static const int PIXEL_SIZE = 16;
    static const int FROG_SIZE = 14;


    // NUMBER OF LIVES A FROG GETS
    static const int MAX_NUM_LIVES = 3;

private:
    sf::Texture frogTexture;
    sf::IntRect frogRect;
    FroggerSoundManager frogSounds;
    Speed frogSpeed;
};


#endif //FROGGER_FROG_H
