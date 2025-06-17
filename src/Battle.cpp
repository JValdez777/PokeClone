//
// Created by Juan Valdez on 6/2/25.
//

#include "Battle.h"


Battle::Battle(const sf::RenderWindow& window)
    :enemyBoss(ENEMYBATTLE,1,16), player(RAYQUAZA,1,12),rayquaza(10,10),gui(window)
{


    music.playMusic("Sounds/KyuremTheme.mp3");


    enemyBoss.setPosition({static_cast<float>(window.getSize().x / 2), static_cast<float>((window.getSize().y / 3/4) - 50 )});
    enemyBoss.setScale({3,3});

    player.setColor({255,255,255,255});
    player.setPosition({-70,static_cast<float>(window.getSize().y / 2) -50});
    player.setScale({3.5,3.5});

    view.zoom(0);
    view.setSize({static_cast<float>(window.getSize().x),static_cast<float>(window.getSize().y)});
    view.setCenter({static_cast<float>(window.getSize().x / 2), static_cast<float>(window.getSize().y / 2)});


}

void Battle::draw(sf::RenderTarget& window, sf::RenderStates states)
{
    window.setView(view);
    sf::Texture texture;
    if (!texture.loadFromFile("images/SnowNightStage.png"))
    {
        std::cout << "Error loading image!" << std::endl;
    }

    sf::Sprite map(texture);
    map.scale({3.5,4});
    window.draw(map);


    player.draw(window,states);
    dmgTaken();
    enemyBoss.draw(window,states);
    gui.draw(window,states);


}

void Battle::handleEvent(sf::RenderWindow& window)
{
    gui.update(window);

}

void Battle::dmgTaken()
{
    if (gui.getActionConfirm() == true)
    {
        // enemyBoss.setColor({255,255,255,0});
        // enemyBoss.setColor({0,0,0,255});
        enemyBoss.setScale({3.5,3.5});

    }
    else
    {
        enemyBoss.setScale({3,3});
    }
}
