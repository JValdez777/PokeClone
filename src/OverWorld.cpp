//
// Created by Juan Valdez on 5/28/25.
//

#include "OverWorld.h"

OverWorld::OverWorld(const sf::RenderWindow& window)
    :player(MAINCHAR),enemy(ENEMY,8,2),enemy2(ENEMYSHOUT,8,10)
{
    player.setPosition({
    static_cast<float>(window.getSize().x / 2) - (player.getGlobalBounds().size.x),
    static_cast<float>(window.getSize().y) - (player.getGlobalBounds().size.y)});
    enemy2.setPosition({-500,-500});
    enemy.setScale({1.5,1.5});
    enemy.setPosition({static_cast<float>(window.getSize().x/2)- 30,0.f});
    musicOver.playMusic("Sounds/OverworldTheme.mp3");
    clock.stop();
}

OverWorld::~OverWorld()
{
}

void OverWorld::draw(sf::RenderTarget& window, sf::RenderStates states)
{
    /// PLAYER AND ENEMY CREATION

    sf::Texture texture;
    if (!texture.loadFromFile("images/updatedmap.png"))
    {
        std::cout << "Error loading image!" << std::endl;
    }

    sf::Sprite map(texture);
    map.setScale({1.2,1.2});

    if (bossFight == true)
    {
        view.setCenter({static_cast<float>(window.getSize().x /2), static_cast<float>(window.getSize().y / 2)});
        view.zoom(1);
    }
    window.draw(map);
    player.draw(window,states);
    enemy.draw(window,states);
    enemy2.draw(window,states);
}

void OverWorld::handleEvent(sf::RenderWindow& window)
{
    sf::Music music("Sounds/KyuremTheme.mp3");


    float seconds = clock.getElapsedTime().asSeconds();
    std::cout << seconds << std::endl;


    ///view
    view.setSize({static_cast<float>(window.getSize().x),static_cast<float>(window.getSize().y)});
    view.zoom(.5);

    ///Getting the player center for the view
    sf::Vector2f playerCenter({(player.getGlobalBounds().position.x + player.getGlobalBounds().size.x/2.0f),
        (player.getGlobalBounds().position.y + player.getGlobalBounds().size.y / 2.0f)});
    /// getting half of the view to set a camera "Boundry"
    sf::Vector2f halfView = view.getSize() / 2.f;

    ///clamp (value, min, max)
    /// view is window size 800 with scale its 400
    /// half view is 200 on the x so 200 pixels in
    /// learned about clamp from gpt
    float camX = std::clamp(playerCenter.x,halfView.x,window.getSize().x - halfView.x);
    float camY = std::clamp(playerCenter.y,halfView.y,window.getSize().y - halfView.y);

    view.setCenter({camX,camY});
    window.setView(view);



    ///Boss Shout Trigger
    if (player.getGlobalBounds().position.y <= (enemy.getGlobalBounds().size.y - player.getGlobalBounds().size.y) )
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        {
            ///need to move over to other stack (boss battle) since this stack will be popped?
            clock.restart();

            music.stop();
            music.openFromFile("Sounds/KyuremTheme.mp3");
            music.play();

            bossShout.play();
            enemy.setPosition({-500,-500});
            enemy2.setPosition({static_cast<float>(window.getSize().x/2)- 30,0.f});
            enemy2.setScale({1.5,1.5});
        }
        if (clock.getElapsedTime().asSeconds() >= 2)
        {

            musicOver.stopMusic();
            bossFight = true;

        }

        // if (bossShout.getStatus() != sf::SoundSource::Status::Playing)
    }

    player.handleInput();
    enemy.update();
    player.update();
}

bool OverWorld::getStatus()
{
    return bossFight;
}
