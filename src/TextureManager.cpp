//
// Created by Juan Valdez on 5/14/25.
//

#include "TextureManager.h"

void TextureManager::load(ImageEnum image)
{
    if (_textures.count(image) == 0)
    {
        _textures[image].loadFromFile(getImagePath(image));
    }
}

std::string TextureManager::getImagePath(ImageEnum image)
{
    switch (image)
    {
        case ROTATEZ: return "images/Rotate-Anim.png";
        case MAINCHAR: return "images/CharacterWalk.png";
        case ENEMY: return "images/WhiteKyuremIdle.png";
        case ENEMYSHOUT: return "images/KyuremCharge.png";
        case ENEMYBATTLE: return "images/KyuremBattleAnimSheet.png";
        case RAYQUAZA: return "images/RAYQUAZAFINAL.png";
    }
}

const sf::Texture & TextureManager::getImage(ImageEnum image)
{
    load(image);
    return _textures[image];
}


