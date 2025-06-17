//
// Created by Juan Valdez on 5/28/25.
//

#ifndef OVERWORLD_H
#define OVERWORLD_H
#include "Player.h"
#include "EnemyOverworld.h"
#include "AudioManager.h"
#include "FontManager.h"
#include "SoundEffect.h"
#include "SoundEnum.h"
#include "Screen.h"



class OverWorld : public Screen
{
   SoundEffect bossShout{SoundEnum::KyuremCry};
   Player player;
   EnemyOverworld enemy;
   EnemyOverworld enemy2;
   AudioManager musicOver;
   sf::View view;
public:
   sf::Clock clock;
   sf::Time time;
   bool bossFight = false;
   OverWorld(const sf::RenderWindow& window);
   ~OverWorld();
   void draw(sf::RenderTarget &window, sf::RenderStates states) override;
   void handleEvent(sf::RenderWindow &window) override;
   bool getStatus() override;

};



#endif //OVERWORLD_H
