#include <SFML/Graphics.hpp>
#include "Player.h"
#include "EnemyOverworld.h"
#include "AudioManager.h"
#include "FontManager.h"
#include "SoundEffect.h"
#include "SoundEnum.h"
#include "OverWorld.h"
#include "GameState.h"
int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({800u, 600u}), "Final Battle");
    window.setFramerateLimit(60);

    GameState gamestate(window);

    /// Background Music and Sound effects
    // AudioManager musicOver;
    // musicOver.playMusic("Sounds/OverworldTheme.mp3");

    while (window.isOpen())
    {
        /// Event Listener
        while (auto event = window.pollEvent())
        {

            /// Event Handling
            if (event->getIf<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        gamestate.EventHandler(window);
        window.draw(gamestate);
        gamestate.getStatus(window);
        window.display();


    }

}
