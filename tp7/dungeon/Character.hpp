#pragma once

#include "Entity.hpp"
#include "Trap.hpp"
#include "Potion.hpp"
#include "Logger.hpp"

class Character: public Entity
{
public:
    Character(int x, int y)
    : Entity(x, y) 
    {}

    ~Character() {
        logger << "A character died at position (" << get_x() << ", " << get_y() << ")";
    }

    char get_representation() const override { 
        switch(life) {
            case 2 : return 'O';
            case 1 : return 'o';
            case 0 : return ' ';
            default : return '?';
        }
    }

    void interact_with(Entity& entity) override {
        auto* trap = dynamic_cast<Trap*>(&entity);
        auto* popo = dynamic_cast<Potion*>(&entity);

        if (trap != nullptr)
        {   
            
            // entity est bien une instance de Trap
            if (life > 0) {
                life--;
                trap->consume();
            }
        }
        if (popo != nullptr)
        {
            // entity est bien une instance de Trap
            if (life <= 1) {
                life++;
                popo->consume();
            }
        }
    }

    bool should_destroy() const override {
        return (life == 0) ? true : false;
    }

private:
    int life = 2;
};
