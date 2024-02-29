#pragma once

#include <ostream>
#include <iostream>
#include <string>


class Material
{
public:
    Material(const std::string& name)
    : _name { name }
    {
        std::cout << _name << " was created !" << std::endl;
    }

    ~Material() {
        std::cout << _name << " was destroyed !" << std::endl;
    }

    // Affiche le nom d'un materiau.
    friend std::ostream& operator<<(std::ostream& stream, const Material& material) { 
        stream << material._name;
        return stream; 
    }

    const std::string& get_name() const { return _name; }
private:
    std::string _name;
};
