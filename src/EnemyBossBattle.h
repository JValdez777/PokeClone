//
// Created by Juan Valdez on 6/4/25.
//

#ifndef ENEMYBOSSBATTLE_H
#define ENEMYBOSSBATTLE_H
#include "AnimatedSprite.h"
#include "EnemyOverworld.h"
#include "TextureManager.h"

class EnemyBossBattle : public EnemyOverworld
{
private:
    AnimatedSprite sprite;
public:
    EnemyBossBattle(ImageEnum spriteEnemy,int rows, int cols);
    void setColor(sf::Color color);


};



#endif //ENEMYBOSSBATTLE_H
