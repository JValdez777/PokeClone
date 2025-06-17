//
// Created by Juan Valdez on 5/14/25.
//

#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H
#include<SFML/Audio.hpp>
#include <iostream>
#include "SoundEnum.h"
#include <map>


class AudioManager
{

    sf::Music current;
public:
    AudioManager();
    void playMusic(const std::string& filename);
    void stopMusic();
    void playSoundEffect(SoundEnum effect);

    static const sf::SoundBuffer& getSound(SoundEnum sound);





};



#endif //AUDIOMANAGER_H
