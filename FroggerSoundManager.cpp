//
// Created by Alexis Rodriguez on 12/1/20.
//

#include "FroggerSoundManager.h"

FroggerSoundManager::FroggerSoundManager(){
    if(!hop.loadFromFile("sounds/sound-frogger-hop.wav")){
        std::cout << "Cannot Load Frogger Hop" << std::endl;
        exit(1);
    }
    if(!squashed.loadFromFile("sounds/sound-frogger-squash.wav")){
        std::cout << "Cannot Load Frogger Squashed" << std::endl;
        exit(1);
    }
    if(!plunk.loadFromFile("sounds/sound-frogger-plunk.wav")){
        std::cout << "Cannot Load Frogger Plunk" << std::endl;
        exit(1);
    }
    if(!coinIn.loadFromFile("sounds/sound-frogger-coin-in.wav")){
        std::cout << "Cannot Load Frogger Coin In" << std::endl;
        exit(1);
    }
    if(!splashScreen.openFromFile("sounds/sound-frogger-splash-screen-music.wav")){
        std::cout << "Cannot Load Frogger Splash Screen Music" << std::endl;
        exit(1);
    }
    if(!arcade.openFromFile("sounds/sound-frogger-arcade-music.wav")){
        std::cout << "Cannot Load Frogger Arcade Music" << std::endl;
        exit(1);
    }
    if(!gameOver.openFromFile("sounds/sound-frogger-gameover-music.wav")){
        std::cout << "Cannot Load Frogger Game Over Music" << std::endl;
        exit(1);
    }
    musicPtr = new sf::Music;
    setState(MUSIC_STATES::PLAY);
}
void FroggerSoundManager::playHop(){
    play(hop);
}
void FroggerSoundManager::playSquash(){
    play(squashed);
}
void FroggerSoundManager::playPlunk(){
    play(plunk);
}
void FroggerSoundManager::playCoinIn(){
    play(coinIn);
}
void FroggerSoundManager::playSplashScreenMusic(){
    play(&splashScreen);
}
void FroggerSoundManager::playArcadeMusic(){
    play(&arcade);
}
void FroggerSoundManager::playGameoverMusic(){
    play(&gameOver);
}
void FroggerSoundManager::play(sf::Music* music){
        if(musicPtr == music){
            if(musicPtr->getStatus() == sf::SoundSource::Playing) {
                if (currentMusicState == MUSIC_STATES::PLAY) {
                    return;
                }
            }
        }
        if(currentMusicState == MUSIC_STATES::PLAY){
            musicPtr->stop();
            musicPtr = music;
            musicPtr->setVolume(MUSIC_VOLUME);
            musicPtr->play();
        }
}
void FroggerSoundManager::play(const sf::SoundBuffer& soundBuffer){
    if(currentMusicState == MUSIC_STATES::PLAY) {
        sound.setBuffer(soundBuffer);
        sound.setVolume(SOUND_VOLUME);
        sound.play();
    }
    else{
        sound.pause();
    }
}
void FroggerSoundManager::reset() {
    musicPtr = &splashScreen;
}
void FroggerSoundManager::pause(){
    setState(MUSIC_STATES::PAUSE);
    musicPtr->pause();
}
void FroggerSoundManager::resume(){
    setState(MUSIC_STATES::PLAY);
    musicPtr->play();
}
MUSIC_STATES FroggerSoundManager::getState() const {
    return currentMusicState;
}
void FroggerSoundManager::setState(MUSIC_STATES currentMusicState) {
    FroggerSoundManager::currentMusicState = currentMusicState;
}