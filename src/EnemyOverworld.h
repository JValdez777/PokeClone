//
// Created by Juan Valdez on 5/14/25.
//

#ifndef ENEMYOVERWORLD_H
#define ENEMYOVERWORLD_H
#include "Player.h"
#include "AnimatedSprite.h"
#include <SFML/Graphics.hpp>
#include "ImageEnum.h"


class EnemyOverworld
{
    AnimatedSprite sprite;
public:
    //EnemyOverworld();
    EnemyOverworld(ImageEnum spriteEnemy,int rows, int cols);
    void setScale(const sf::Vector2f& scale);
    void setPosition(const sf::Vector2f pos);

    void draw(sf::RenderTarget& window, sf::RenderStates states);
    void update();
    sf::FloatRect getGlobalBounds();



};


#endif //ENEMYOVERWORLD_H
