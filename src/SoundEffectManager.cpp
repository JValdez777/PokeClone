//
// Created by Juan Valdez on 5/23/25.
//

#include "SoundEffectManager.h"


std::string SoundEffectManager::getSoundPath(SoundEnum sound)
{
    switch (sound)
    {
        case KyuremCry: return"Sounds/KyuremShout.mp3";
        case SELECT: return "Sounds/selectSFX.mp3";
        case HIT: return "Sounds/hitFX.mp3";
    }
}

void SoundEffectManager::load(SoundEnum sound)
{
    if (_sounds.count(sound) == 0)
    {
        _sounds[sound].loadFromFile(getSoundPath(sound));
    }
}

const sf::SoundBuffer & SoundEffectManager::getSound(SoundEnum sound)
{
    load(sound);
    return _sounds[sound];
}
