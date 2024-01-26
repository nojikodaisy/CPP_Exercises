#pragma once
#include <iomanip>
#include <iostream>
#include <vector>
#include "Card.hpp"

class Player 
{
public:
    static inline unsigned int turn_number = 0;

    Player(const std::string& name);

    static void deal_all_cards(Player& p1, Player& p2);

    void set_cards(std::vector<Card> cards) { _cards = cards; }

    Card operator[](int i) const { return _cards[i]; }

    static bool play(Player& p1, Player& p2);

    unsigned int score() const { return _score; }

private:
    std::string _name;
    std::vector<Card> _cards;
    unsigned int _score = 0;
};