#pragma once

#include <string>

class DerivedString: public Base
{
public:
    DerivedString(std::string str)
    : _str { std::move(str) }
    {}

    const std::string& data() const { return _str; }

    bool is_null() const {
        return _str == "";
    }

    std::string to_string() const override { return _str; }

private:
    std::string _str;
};
