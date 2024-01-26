#include <iomanip>
#include <iostream>
#include <algorithm>
#include <random>
#include "Player.hpp"

Player::Player(const std::string& name) 
    : _name { name }
    {}

void Player::deal_all_cards(Player& p1, Player& p2) {
    std::vector<Card> all_cards;
    for (int i = 7; i < 15; i++) {
        for (auto color : { "Trèfle", "Carreau", "Pique", "Coeur" } ) {
            all_cards.emplace_back(Card(i, color));
        }
    }

    std::random_device rd;
    std::shuffle(all_cards.begin(), all_cards.end(), std::default_random_engine(rd()));

    std::vector<Card> cards1;
    std::vector<Card> cards2;
    for (int c = 0 ; c < all_cards.size(); c++) {
        if ( c >= all_cards.size() / 2) {
            cards2.emplace_back(all_cards[c]);
        } else {
            cards1.emplace_back(all_cards[c]);
        }
    }
    p1.set_cards(cards1);
    p2.set_cards(cards2);
}

bool Player::play(Player& p1, Player& p2) {
    std::cout << "Tour " << turn_number << std::endl;
    std::cout << "Player 1 joue " << p1[turn_number] << std::endl;
    std::cout << "Player 2 joue " << p2[turn_number] << std::endl;


    if (p1[turn_number] < p2[turn_number]) {
        std::cout << "Player 2 gagne" << std::endl;
        p2._score++;
    } else if (p2[turn_number] < p1[turn_number]) {
        std::cout << "Player 1 gagne" << std::endl;
        p1._score++;
    } 
    turn_number++;
    return turn_number == 16;
}