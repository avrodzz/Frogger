//
// Created by Alexis Rodriguez on 12/2/20.
//

#include "Log.h"

sf::Texture Log::smallLog, Log::mediumLog, Log::largeLog;

Log::Log(int type){
    loadAllTextures();
    setLogSize(type);
}
int Log::getSpriteSize() const{
    return spriteSize;
}
void Log::loadAllTextures(){
    if(!smallLog.loadFromFile(logFileNames[0])){
        std::cout << logFileNames[0] << " could not be loaded into smallLog" << std::endl;
        exit(1);
    }
    if(!mediumLog.loadFromFile(logFileNames[1])){
        std::cout << logFileNames[1] << " could not be loaded into mediumLog" << std::endl;
        exit(1);
    }
    if(!largeLog.loadFromFile(logFileNames[2])){
        std::cout << logFileNames[2] << " could not be loaded into largeLog" << std::endl;
        exit(1);
    }
}
void Log::setLogSize(int type){
    switch(type){
        case LOG_SIZES::SMALL:
            setTexture(smallLog);
            spriteSize = SMALL_LOG_SIZE;
            break;
        case LOG_SIZES::MEDIUM:
            setTexture(mediumLog);
            spriteSize = MEDIUM_LOG_SIZE;
            break;
        case LOG_SIZES::LARGE:
            setTexture(largeLog);
            spriteSize = LARGE_LOG_SIZE;
            break;
    }
}
