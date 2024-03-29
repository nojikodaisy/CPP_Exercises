#pragma once

#include "Random.hpp"

class Entity
{
public:
    Entity() = default;

    Entity(int x, int y)
        : _x { x }
        , _y { y }
    {}

    virtual ~Entity() = default;

    int get_x() const { return _x; }
    int get_y() const { return _y; }

    virtual char get_representation() const = 0; // pour empêcher l'instanciation directe du type Entity (virtuelle pure)

    virtual void update() { random_move(_x, _y); }

    virtual void interact_with(Entity& entity) {}

    virtual bool should_destroy() const {
        return false;
    } 

private:
    int _x = 0;
    int _y = 0;
};
