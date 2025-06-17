//
// Created by Juan Valdez on 6/2/25.
//

#ifndef BATTLE_H
#define BATTLE_H
#include "Screen.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include "AudioManager.h"
#include "EnemyBossBattle.h"
#include "Pokemon.h"
#include "battleGUI.h"
#include "SoundEffect.h"

/// A simple Battle state that performs an integrated grid-based transition
class Battle : public Screen
{
private:
    SoundEffect hitsfx{SoundEnum::HIT};
    SoundEffect confirmsfx{SoundEnum::SELECT};

    battleGUI gui;
    EnemyBossBattle enemyBoss;
    EnemyBossBattle player;

    //AudioManager music;
    sf::Music musicBattle;
    AudioManager music;
    sf::View view;
    Pokemon rayquaza;


public:
    Battle(const sf::RenderWindow& window);
    void draw(sf::RenderTarget& window, sf::RenderStates states) override;
    void handleEvent(sf::RenderWindow& window) override;
    void dmgTaken();
};



#endif //BATTLE_H
