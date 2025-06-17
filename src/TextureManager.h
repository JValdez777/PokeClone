//
// Created by Juan Valdez on 5/14/25.
//

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <map>

#include "ImageEnum.h"
#include "SFML/Graphics/Texture.hpp"

/// To add another image to your texture manager
/// 1. Add a new enum to ImageEnum.h
/// 2. Add a new case to getImagePath
class TextureManager
{
    static inline std::map<ImageEnum, sf::Texture> _textures;
    static void load(ImageEnum image);
    static std::string getImagePath(ImageEnum image);
public:
    static const sf::Texture& getImage(ImageEnum image);

};



#endif //TEXTUREMANAGER_H
