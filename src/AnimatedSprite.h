//
// Created by Juan Valdez on 5/14/25.
//

#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H
#include <SFML/Graphics.hpp>
#include "ImageEnum.h"
#include "KeyControls.h"

//for a sprite sheet to box the image prop divde width by amount of sprites
// same with rows
class AnimatedSprite : public sf::Sprite
{
    sf::Clock _clock;
    int _rows, _cols;
    sf::IntRect _intRect;
    KeyControls _key_controls;
public:
    AnimatedSprite(const sf::Texture& texture, int rows, int cols);
    void setKeyControls(const KeyControls& key_controls);
    void animate();
    void setFrame(int row);
};



#endif //ANIMATEDSPRITE_H