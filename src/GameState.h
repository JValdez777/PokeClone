//
// Created by Juan Valdez on 5/15/25.
//

#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "Screen.h"
#include <stack>
#include "GameStateEnum.h"
#include <SFML/Graphics.hpp>
#include "OverWorld.h"
#include "Battle.h"

class GameState : public sf::Drawable
{
private:

    std::stack<GAMESTATEENUM> _stack;
    Screen *p;
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;

public:
    GameState(const sf::RenderWindow& window);
    void pop(const sf::RenderWindow& window);
    Screen* getNewScreen(GAMESTATEENUM state,const sf::RenderWindow& window);
    void EventHandler(sf::RenderWindow& window);
    void checkEvent();
    bool getStatus(sf::RenderWindow& window);

};



#endif //GAMESTATE_H
