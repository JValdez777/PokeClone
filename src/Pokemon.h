//
// Created by Juan Valdez on 6/4/25.
//

#ifndef POKEMON_H
#define POKEMON_H
#include <cstdlib>



class Pokemon
{
private:
    int hp,attack,maxHp;
public:
    Pokemon(int hp, int attack);
    bool isFainted();
    void takeDmg(int amount);
    int calculateCrit();

    int getHP();
    int getAttack();
    int getMaxhp();
    int calculateDMG();


};



#endif //POKEMON_H
