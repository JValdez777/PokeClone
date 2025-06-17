//
// Created by Juan Valdez on 5/15/25.
//

#include "KeyControls.h"

KeyControls::KeyControls()
    : up({sf::Keyboard::Key::W,3}),
right({sf::Keyboard::Key::D,2}),
left({sf::Keyboard::Key::A,1}),
down({sf::Keyboard::Key::S,0})
{

}

KeyControls::KeyControls(const KeyControl &up, const KeyControl &right, const KeyControl &left, const KeyControl &down)
    :up(up),right(right),left(left),down(down)
{

}

void KeyControls::set_up(const KeyControl &up)
{
    this->up = up;
}

void KeyControls::set_right(const KeyControl &right)
{
    this->right = right;
}

void KeyControls::set_down(const KeyControl &down)
{
    this->down = down;
}

void KeyControls::set_left(const KeyControl &left)
{
    this->left = left;
}

KeyControl KeyControls::get_up() const
{
    return up;
}

KeyControl KeyControls::get_right() const
{
    return right;
}

KeyControl KeyControls::get_down() const
{
    return down;
}

KeyControl KeyControls::get_left() const
{
    return left;
}
