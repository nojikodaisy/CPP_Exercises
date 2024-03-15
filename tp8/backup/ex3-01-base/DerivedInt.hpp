#pragma once

#include <string>

class DerivedInt: public Base
{
public:
    DerivedInt(int a)
    : _value { a }
    {}

    int data() const {
        return _value;
    }

    bool is_null() const {
        return _value == 0;
    }

    std::string to_string() const override { return std::to_string(_value); }

private:
    int _value;
};

