//
// Created by Alexis Rodriguez on 11/10/20.
//

#include "Grid.h"

Grid::Grid(){
    filePath = "images/frogGrid.png";
    if(!gridTexture.loadFromFile(filePath)){
        std::cout << filePath << " could not be loaded into gridTexture" << std::endl;
        exit(1);
    }
    grid.setTexture(gridTexture);
    view.setSize(ORIGINAL_SCREEN_WIDTH,ORIGINAL_SCREEN_HEIGHT);
    view.setCenter(ORIGINAL_SCREEN_WIDTH / 2, ORIGINAL_SCREEN_HEIGHT / 2);
}
void Grid::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    /*
     *  1. Draw the background colors first (#000047 and #000000) then layer the rest on top
     *  2. Draw out the Frogger title
     *     REMEMBER: YOU WANT TO DRAW OUT THE TITLE AND THEN ONCE THE A KEY IS PRESSED TO START THE
     *               GAME THEN THE POINTS ARE DISPLAYED!
     *  3. Draw the green shrub and the two purple shrubs
     *  4. Draw the time text that is at the bottom right of the game board
     */

    window.draw(grid);
}
sf::View Grid::getView() const{
    return view;
}