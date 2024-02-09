#pragma once
#include "PhoneBookEntry.hpp"
#include <list>
class PhoneBook
{
public:
    PhoneBook() {}

    bool add_entry(const PhoneBookEntry& entry);

    const PhoneNumber* get_number(const std::string& name);


private:
    std::list<PhoneBookEntry> book;
};
