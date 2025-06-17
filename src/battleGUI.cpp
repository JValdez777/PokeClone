#include "battleGUI.h"

battleGUI::battleGUI(const sf::RenderTarget& window)
    :textMenu(FontManager::getFont(POKEMON)),cursor(FontManager::getFont(POKEMON)),run(FontManager::getFont(POKEMON)),fight(FontManager::getFont(POKEMON))
,Rayquaza(50,10),Boss(100,10)
{
    hitsfx.setVolume(100);

    healthbar.setSize({healthx,healthy});
    healthbar.setFillColor(sf::Color::Red);
    healthbar.setPosition({50,20});

    healthBG.setSize({healthx,healthy});
    healthBG.setFillColor(sf::Color::Black);
    healthBG.setPosition({50,20});


    textMenu.setCharacterSize(25);
    textMenu.setFillColor(sf::Color::White);
    textMenu.setString("FIGHT\nRUN");
    textMenu.setPosition({static_cast<float>(window.getSize().x - 180) ,window.getSize().y - background.getSize().y});

    background.setSize({static_cast<float>(window.getSize().x),125});
    background.setFillColor({0,0,0,200});
    background.setPosition({0,window.getSize().y - background.getSize().y});

    cursor.setPosition({static_cast<float>(window.getSize().x - 210) ,window.getSize().y - background.getSize().y});
    cursor.setCharacterSize(25);
    cursor.setFillColor(sf::Color::White);
    cursor.setString(">");

    fight.setCharacterSize(25);
    fight.setFillColor(sf::Color::White);
    fight.setString("FIGHT");
    fight.setPosition({static_cast<float>(window.getSize().x - 180) ,window.getSize().y - background.getSize().y});

    run.setCharacterSize(25);
    run.setFillColor(sf::Color::White);
    run.setString("RUN");
    run.setPosition({static_cast<float>(window.getSize().x - 180) ,static_cast<float>(window.getSize().y - background.getSize().y/1.5)});

    menuItems.push_back(run);
    menuItems.push_back(fight);

}

void battleGUI::draw(sf::RenderTarget& window, sf::RenderStates states)
{
    window.draw(background);
    for (auto text : menuItems)
    {
        window.draw(text);
    }
    window.draw(healthBG);
    window.draw(healthbar);
    window.draw(cursor);

}

void battleGUI::update(sf::RenderTarget& window)
{
    handleEvent(window);
    if (actionConfirmed == true)
    {
        hitsfx.play();
        int dmg = Rayquaza.calculateDMG();
        Boss.takeDmg(dmg);
        updateHealth(dmg);
        actionConfirmed = false;
    }
}
bool battleGUI::getActionConfirm()
{
    return actionConfirmed;
}

void battleGUI::updateHealth(int dmg)
{
    std::cout << "Remaining boss hp: " << Boss.getHP() <<std::endl;
    std::cout << "dmg done: " << dmg << std::endl;
    healthbar.setSize({healthx * Boss.getHP()/ Boss.getMaxhp(),healthy});
}



void battleGUI::handleEvent(sf::RenderTarget& window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {

        cursor.setPosition({static_cast<float>(window.getSize().x - 210),static_cast<float>(window.getSize().y - textMenu.getGlobalBounds().size.y - 20)});
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {

        cursor.setPosition({static_cast<float>(window.getSize().x - 210) ,window.getSize().y - background.getSize().y});
    }

    bool enterNow = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter);
    if (enterNow && !enterInactive) {
        // Enter has just gone down this frame (was up last frame)
        confirmsfx.play();
        actionConfirmed = true;
    }
    // Update the “was down” flag for next frame
    enterInactive = enterNow;
}


