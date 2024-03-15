#pragma once 

#include <ostream>

class Base
{
public:
    virtual bool is_null() const = 0;

    friend std::ostream& operator<<(std::ostream& stream, const Base& polygon) {
        return stream << polygon.to_string();
    }

    virtual std::string to_string() const = 0;
};

