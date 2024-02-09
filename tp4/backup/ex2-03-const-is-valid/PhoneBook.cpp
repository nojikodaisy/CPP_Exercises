#include "PhoneBook.hpp"

bool PhoneBook::add_entry(const PhoneBookEntry& entry) {
    for (auto b : book) {
        if (b == entry) {
            return false;
        }
    }
    book.emplace_back(entry);
    return true;
}

const PhoneNumber* PhoneBook::get_number(const std::string& name) {
    for(const auto& b : book) {
        if (b.get_name() == name) {
            return &b.get_number();
        }
    }
    return nullptr;
}