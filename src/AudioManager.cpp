//
// Created by Juan Valdez on 5/14/25.
//

#include "AudioManager.h"
///SOUND EFFECTS


void AudioManager::playSoundEffect(SoundEnum effect)
{

}


AudioManager::AudioManager()
{

}

void AudioManager::playMusic(const std::string& filename) {
    if (!current.openFromFile(filename)) {
        std::cout << "AudioManager: failed to load “" << filename << "”\n";
        return;
    }
    current.setVolume(100.f);
    current.setLooping(true);
    current.play();
    std::cout << "AudioManager: playing “" << filename << "”\n";
}


void AudioManager::stopMusic()
{
    current.stop();
}

