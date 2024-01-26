#include <iomanip>
#include <iostream>
#include "Card.hpp"

Card::Card(unsigned int value, std::string color)
        : _value { value }
        , _color { color }
        {}

unsigned int Card::get_value() const {
    return _value;
}

const std::string& Card::get_color() const {
    return _color;
}

void Card::print() const {
    std::cout << get_value() << " de " << get_color() << std::endl;
}

bool Card::operator==(const Card& c1) const {
    return c1.get_value() == get_value();
}

bool Card::operator<(const Card& c1) const {
    return get_value() < c1.get_value();
}

std::ostream& operator<<(std::ostream& stream, const Card& card) {
    stream << card.get_value() << " de " << card.get_color();
    return stream;
}