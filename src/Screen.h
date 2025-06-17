//
// Created by Juan Valdez on 5/28/25.
//

#ifndef SCREEN_H
#define SCREEN_H
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RenderWindow.hpp"


class Screen
{
private:
public:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states);
    virtual void handleEvent(sf::RenderWindow& window);
    virtual bool getStatus();
};



#endif //SCREEN_H
