#include <iomanip>
#include <iostream>
#include "Person.hpp"

Person::Person(std::string first_name, std::string surname)
        : _first_name { first_name }
        , _surname { surname }
        {}

std::string Person::get_firstname() {
    return _first_name;
}

std::string Person::get_surname() {
    return _surname;
}