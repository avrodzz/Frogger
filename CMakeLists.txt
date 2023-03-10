cmake_minimum_required(VERSION 3.17)
project(Frogger)

set(CMAKE_CXX_STANDARD 14)

add_executable(Frogger main.cpp Grid.h Grid.cpp GameTitle.cpp GameTitle.h
        Shrub.cpp Shrub.h Frog.cpp Frog.h StaticBackground.cpp StaticBackground.h
        Background.cpp Background.h GreenShrub.cpp GreenShrub.h PurpleShrub.cpp PurpleShrub.h
        Vehicle.cpp Vehicle.h YellowCar.cpp YellowCar.h Bulldozer.cpp Bulldozer.h PinkCar.cpp
        PinkCar.h WhiteCar.cpp WhiteCar.h Truck.cpp Truck.h Collision.cpp Collision.h
        Const_Node_Iterator.h Const_Node_Iterator.cpp LinkedList.h LinkedList.cpp
        Node.cpp Node.h Node_Iterator.h Node_Iterator.cpp Queue.h Queue.cpp Stack.h Stack.cpp FrogLife.cpp FrogLife.h FrogLifeTracker.cpp FrogLifeTracker.h FroggerGameState.cpp FroggerGameState.h FroggerSoundManager.cpp FroggerSoundManager.h Log.cpp Log.h LogLane.cpp LogLane.h Direction.cpp Direction.h Speed.cpp Speed.h Frogger.cpp Frogger.h States.cpp States.h MusicStates.cpp MusicStates.h SplashScreenGameState.cpp SplashScreenGameState.h FrogWinGameState.cpp FrogWinGameState.h FrogWinSprite.cpp FrogWinSprite.h FrogWinBounds.cpp FrogWinBounds.h FrogWin.cpp FrogWin.h Text.cpp Text.h StaticSplashBackground.cpp StaticSplashBackground.h)

target_link_libraries(Frogger sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)