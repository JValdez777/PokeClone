//
// Created by Juan Valdez on 5/20/25.
//

#ifndef FONTMANAGER_H
#define FONTMANAGER_H
#include "SFML/Graphics/Font.hpp"
#include <map>
#include "FontEnum.h"

class FontManager
{
    static inline std::map<FontEnum, sf::Font> _fonts;
    static void load(FontEnum font);
    static std::string getFontPath(FontEnum font);
    //std::string getPath(FontEnum image) override;

public:
    static const sf::Font& getFont(FontEnum font);
};



#endif //FONTMANAGER_H
