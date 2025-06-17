//
// Created by Juan Valdez on 6/4/25.
//

#ifndef BATTLEGUI_H
#define BATTLEGUI_H
#include "FontManager.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "SoundEffect.h"
#include "Pokemon.h"

class battleGUI
{
private:
    sf::RectangleShape background;
    sf::Text textMenu,cursor,run,fight;
    Pokemon Rayquaza,Boss;

    SoundEffect confirmsfx{SoundEnum::SELECT};
    SoundEffect hitsfx{SoundEnum::HIT};



    bool actionConfirmed = false;
    bool enterInactive = false;

    float healthx = 200, healthy = 15;
    sf::RectangleShape healthbar;
    sf::RectangleShape healthBG;
    std::vector<sf::Text> menuItems;
    int index = 0;

public:
    battleGUI(const sf::RenderTarget& window);
    void draw(sf::RenderTarget& window, sf::RenderStates states);
    void update(sf::RenderTarget& window);
    bool getActionConfirm();

    void moveCursor();
    void handleEvent(sf::RenderTarget& window);
    void updateHealth(int dmg);
};



#endif //BATTLEGUI_H
