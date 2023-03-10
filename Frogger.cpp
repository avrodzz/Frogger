//
// Created by Alexis Rodriguez on 12/6/20.
//

#include "Frogger.h"

Frogger::Frogger(){
    setState(STATES::FROGGER_GAME);
}
void Frogger::setState(STATES state){
    currentState = state;
}
void Frogger::addEvents(sf::RenderTarget& window, sf::Event event){
    if (event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::P){
            lastState = currentState;
            currentState = STATES::PAUSE;
        }
        if(event.key.code == sf::Keyboard::R){
            currentState = lastState;
            switch(currentState) {
                case STATES::SPLASH_SCREEN:
                    splashScreen.resumeMusic();
                    break;
                case FROGGER_GAME:
                    froggerGame.resumeMusic();
                    break;
                case GAMEOVER:
                    break;
                case PAUSE:
                    break;
                case GAME_WON:
                    break;
            }
        }
    }

    switch(currentState){
        case STATES::SPLASH_SCREEN:
            splashScreen.addEvents(window, event);
            if(splashScreen.getState() != currentState){
                splashScreen.pauseMusic();
                setState(splashScreen.getState());
            }
            break;
        case STATES::FROGGER_GAME:
            froggerGame.addEvents(window, event);
            break;
        case STATES::GAMEOVER:
            break;
        case STATES::PAUSE:
            splashScreen.pauseMusic();
            froggerGame.pauseMusic();
            break;
        case STATES::GAME_WON:
            break;
    }

}
void Frogger::update(sf::RenderTarget& window, sf::Event event){
    switch(currentState){
        case STATES::SPLASH_SCREEN:
            splashScreen.update(window,event);
            break;
        case STATES::FROGGER_GAME:
            froggerGame.update(window,event);
            if(froggerGame.getState() != currentState){
                setState(froggerGame.getState());
                froggerGame.pauseMusic();
            }
            break;
        case STATES::GAMEOVER:
            break;
        case STATES::PAUSE:
            break;
        case STATES::GAME_WON:
            break;
    }
}
void Frogger::run(){
    sf::RenderWindow window(sf::VideoMode(ORIGINAL_GAME_SIZE_WIDTH * SCALE,ORIGINAL_GAME_SIZE_HEIGHT * SCALE), "Frogger!");

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
            addEvents(window,event);
        }
        update(window,event);

        if(currentState != STATES::PAUSE){
            switch (currentState) {
                case SPLASH_SCREEN:
                    break;
                case FROGGER_GAME:
                    froggerGame.run();
                    break;
                case GAMEOVER:
                    break;
                case PAUSE:
                    break;
                case GAME_WON:
                    break;
            }

            window.clear();
            switch(currentState){
                case STATES::SPLASH_SCREEN:
                    splashScreen.addMusic();
                    window.draw(splashScreen);
                    break;
                case STATES::FROGGER_GAME:
                    froggerGame.addMusic();
                    window.draw(froggerGame);
                    break;
                case STATES::GAMEOVER:
                    break;
                case STATES::PAUSE:
                    break;
                case STATES::GAME_WON:
                    break;
            }
            window.display();
        }
    }
}