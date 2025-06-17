
#include "GameState.h"


GameState::GameState(const sf::RenderWindow& window)
{
    _stack.push(OVERWORLD);
    _stack.push(BATTLE);
    p = getNewScreen(OVERWORLD,window);
}
///bool in overworld to check if active if not pop the stack from here
bool GameState::getStatus(sf::RenderWindow & window)
{
    if (p -> getStatus() == true)
    {
        //std::cout << "About to pop p is ay" << p << "\n";
        pop(window);
        std::cout << "stack popped!" << std::endl;


    }
}

void GameState::pop(const sf::RenderWindow& window)
{
    delete p;
    p = getNewScreen(_stack.top(),window);
}

Screen* GameState::getNewScreen(GAMESTATEENUM state, const sf::RenderWindow& window)
{
    switch (state)
    {
        case OVERWORLD: return new OverWorld(window);
        case BATTLE: return new Battle(window);
    }
}

void GameState::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    p -> draw(window,states);
}

void GameState::EventHandler(sf::RenderWindow& window)
{
    p -> handleEvent(window);
}


