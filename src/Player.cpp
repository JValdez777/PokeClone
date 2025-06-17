//
// Created by Juan Valdez on 5/12/25.
//

#include "Player.h"

//Constuctor for setting the players initial position and setting up the circles initial radius
Player::Player(ImageEnum spriteChar) : sprite(TextureManager::getImage(spriteChar), 4, 3)
{
}

sf::FloatRect Player::getSize() const
{
    return sprite.getGlobalBounds();
}

void Player::setScale(const sf::Vector2f& scale)
{
    sprite.setScale({scale});
}

void Player::setPosition(const sf::Vector2f pos)
{
    sprite.setPosition(pos);
}

//Will handle the keys that the player must press to move
void Player::handleInput()
{
    velocity = {0.f, 0.f};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        velocity.y  -= 2.5;
        sprite.setFrame(0);
        sprite.animate();



    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        velocity.x -= 2.5;
        sprite.setFrame(2);
        sprite.animate();

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        velocity.y  += 2.5;
        sprite.setFrame(1);
        sprite.animate();

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        velocity.x  += 2.5;
        sprite.setFrame(3);
        sprite.animate();

    }
}

//This will make the character move
void Player::update()
{
    sprite.move({velocity});
    ///clamp position?
    ///clampPosition(shape,windowSize,Radius)
}

//will draw the shape within the window
void Player::draw(sf::RenderTarget& window, sf::RenderStates states)
{
    window.draw(sprite);
}

sf::FloatRect Player::getGlobalBounds()
{
    return sprite.getGlobalBounds();
}


