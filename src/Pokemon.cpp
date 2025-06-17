//
// Created by Juan Valdez on 6/4/25.
//

#include "Pokemon.h"


Pokemon::Pokemon(int hp, int attack)
    :hp(hp),attack(attack),maxHp(hp)
{
}

bool Pokemon::isFainted()
{
    if (hp <= 0)
    {
        return true;
    }
    else
        return false;
}

void Pokemon::takeDmg(int amount)
{
    hp -= amount;
}

int Pokemon::calculateCrit()
{
    int randCritMultiplier = ((rand() % 100)+1); /// got this percentage idea from chat orginially was going to do only evens
    if (randCritMultiplier <= 25)
    {
        return 2;
    }
    else
        return 1;
}

int Pokemon::getAttack()
{
    return attack;
}

int Pokemon::getHP()
{
    return hp;
}
int Pokemon::getMaxhp()
{
    return maxHp;
}


int Pokemon::calculateDMG()
{
    int dmg = attack * calculateCrit();
    return dmg;
}



