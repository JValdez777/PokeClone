//
// Created by Juan Valdez on 5/12/25.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"
#include "TextureManager.h"



class Player
{
private:
    AnimatedSprite sprite;
    sf::Vector2f velocity;

public:

    Player(ImageEnum spriteChar);

    void setScale(const sf::Vector2f& scale);
    void setPosition(const sf::Vector2f pos);

    sf::FloatRect getSize() const;

    void handleInput();
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states);
    sf::FloatRect getGlobalBounds();
};



#endif //PLAYER_H
