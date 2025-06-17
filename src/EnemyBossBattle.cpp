//
// Created by Juan Valdez on 6/4/25.
//

#include "EnemyBossBattle.h"



EnemyBossBattle::EnemyBossBattle(ImageEnum spriteEnemy, int rows, int cols)
    : EnemyOverworld(spriteEnemy, rows, cols), sprite(TextureManager::getImage(spriteEnemy), rows, cols)
{

}

void EnemyBossBattle::setColor(sf::Color color)
{
    sprite.setColor(color);
}
