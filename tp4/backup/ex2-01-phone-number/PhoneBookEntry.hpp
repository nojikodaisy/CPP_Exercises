#pragma once

#include <string>
#include "PhoneNumber.hpp"

class PhoneBookEntry {
public:
    PhoneBookEntry(std::string name, PhoneNumber phone)
        : _name { name },
        _phone { phone }
    {}

    const std::string& get_name() const;

    const PhoneNumber& get_number() const;

    const bool operator==(const PhoneBookEntry& other) const;

private:
    std::string _name;
    PhoneNumber _phone;
};

