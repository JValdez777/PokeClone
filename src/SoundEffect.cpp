//
// Created by Juan Valdez on 5/23/25.
//

#include "SoundEffect.h"


SoundEffect::SoundEffect(SoundEnum sound)
    :sf::Sound(SoundEffectManager::getSound(sound))
{
    //setBuffer(SoundEffectManager::get(sound));
}

