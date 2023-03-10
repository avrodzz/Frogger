//
// Created by Alexis Rodriguez on 11/10/20.
//

#ifndef SFML_FROGGER_STATICGAMEBOARD_H
#define SFML_FROGGER_STATICGAMEBOARD_H

#include <SFML/Graphics.hpp>
#include <iostream>

// This Grid class draws and scales all the static components to the screen.
class Grid : public sf::Drawable, public sf::Transformable {
public:

    // Takes care of the size of the actual gameBoard...
    // - Note to self: Figure out a way to scale everything to the size of the window.
    Grid();

    // Draws out all the static (non-moving) components featured in the game
    virtual void draw(sf::RenderTarget& window,sf::RenderStates states) const;

    sf::View getView() const;

    static const int ORIGINAL_SCREEN_WIDTH = 240;
    static const int ORIGINAL_SCREEN_HEIGHT = 256;

private:
    std::string filePath;
    sf::Texture gridTexture;
    sf::Sprite grid;
    sf::View view;
};


#endif //SFML_FROGGER_STATICGAMEBOARD_H
