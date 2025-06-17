//
// Created by Juan Valdez on 5/14/25.
//

#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(const sf::Texture &texture, int rows, int cols)
    : sf::Sprite(texture), _rows(rows), _cols(cols)
{
    _intRect.size.x = texture.getSize().x / _cols ;
    _intRect.size.y = texture.getSize().y  / _rows ;
    setTexture(texture);
    setTextureRect(_intRect);
}




void AnimatedSprite::setFrame(int row)
{
    _intRect.position.y = row * _intRect.size.y;

}

void AnimatedSprite::animate()
{
    if (_clock.getElapsedTime().asMilliseconds() > 200)
    {
        int width = _intRect.size.x;
        int imgWidth = getTexture().getSize().x;
        if (_intRect.position.x + 1 * width >= imgWidth)
        {
            _intRect.position.x = 0;
        }
        else
            _intRect.position.x += _intRect.size.x;
        _clock.restart();
        setTextureRect(_intRect);
    }
}

void AnimatedSprite::setKeyControls(const KeyControls &key_controls)
{
    _key_controls = key_controls;
}

/// To use key controls
/// apply this to player instead now
///
///in handle event here
///
/// if (sf::keyboard::isKeyPressed(_key_controls.get_up().direction)
///     y = _key_controls.get_up().row * _intRect.size.y;
