//
// Created by Juan Valdez on 5/23/25.
//

#ifndef SOUNDEFFECT_H
#define SOUNDEFFECT_H
#include "SFML/Audio/Sound.hpp"
#include "SoundEnum.h"
#include <map>
#include "SoundEffectManager.h"


class SoundEffect : public sf::Sound
{
public:
    SoundEffect(SoundEnum sound);
};



#endif //SOUNDEFFECT_H
