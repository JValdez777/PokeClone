//
// Created by Juan Valdez on 5/15/25.
//

#ifndef KEYCONTROLS_H
#define KEYCONTROLS_H
#include<SFML/Graphics.hpp>

struct KeyControl {
    sf::Keyboard::Key direction;
    int row;
};

class KeyControls {
private:
    KeyControl up, right, down, left;
public:

    KeyControls();
    KeyControls(const KeyControl& up,const KeyControl& right, const KeyControl& left, const KeyControl& down);
    KeyControl get_up() const;
    KeyControl get_right() const;
    KeyControl get_down() const;
    KeyControl get_left() const;
    void set_up(const KeyControl &up);
    void set_right(const KeyControl &right);
    void set_down(const KeyControl &down);
    void set_left(const KeyControl &left);
};



#endif //KEYCONTROLS_H
