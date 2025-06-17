//
// Created by Juan Valdez on 5/23/25.
//

#ifndef SOUNDEFFECTMANAGER_H
#define SOUNDEFFECTMANAGER_H
#include <map>
#include "SoundEnum.h"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"
///example class
// class TextureManager : public Manager<ImageEnum, sf::texture> {
//     std::string getPath(ImageEnum image);
// };

class SoundEffectManager
{
    static std::string getSoundPath(SoundEnum sound);
    static inline std::map<SoundEnum, sf::SoundBuffer> _sounds;
    static void load(SoundEnum image);
public:
    static const sf::SoundBuffer& getSound(SoundEnum sound);
};



#endif //SOUNDEFFECTMANAGER_H
