//
// Created by Juan Valdez on 5/20/25.
//

#include "FontManager.h"

void FontManager::load(FontEnum font)
{
    if (_fonts.count(font) == 0)
    {
        _fonts[font].openFromFile(getFontPath(font));
    }
}

std::string FontManager::getFontPath(FontEnum font)
{
    switch (font)
    {
        case DUNE: return "fonts/Dune_Rise.otf";
        case POKEMON: return "fonts/Pokemon Classic.ttf";
    }
}

const sf::Font & FontManager::getFont(FontEnum font)
{
    load(font);
    return _fonts[font];
}