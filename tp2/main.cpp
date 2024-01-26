#include <iomanip>
#include <iostream>
#include <chrono>
#include <thread>
#include "Player.hpp"


int main() {
    Player p1 { "Gerald" };
    Player p2 { "Julien" };
    Player::deal_all_cards(p1, p2);

    while(!Player::play(p1, p2)) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "Score final : " << std::endl;
    std::cout << "Player 1 : " << p1.score() << "Player 2 : " << p2.score() << std::endl;
}