//
// Created by Juan Valdez on 5/14/25.
//

#include "EnemyOverworld.h"

EnemyOverworld::EnemyOverworld(ImageEnum spriteEnemy,int rows, int cols)
: sprite(TextureManager::getImage(spriteEnemy), rows, cols)
{

}

void EnemyOverworld::setScale(const sf::Vector2f& scale)
{
    sprite.setScale({scale});
}

void EnemyOverworld::setPosition(const sf::Vector2f pos)
{
    sprite.setPosition(pos);
}


void EnemyOverworld::draw(sf::RenderTarget& window, sf::RenderStates states)
{
    sprite.animate();
    window.draw(sprite);
}

void EnemyOverworld::update()
{
}

sf::FloatRect EnemyOverworld::getGlobalBounds()
{
    return sprite.getGlobalBounds();
}





