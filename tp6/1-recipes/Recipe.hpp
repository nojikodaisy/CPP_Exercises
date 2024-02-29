#pragma once

#include <ostream>
#include <string>
#include <vector>


class Recipe
{   
public:
    static inline size_t next_id = 0;

    Recipe(std::vector<std::string> materials, std::vector<std::string> products) :
    _materials { materials },
    _products { products },
    _id { ++next_id }
    {}

    // Affiche l'identifiant et la formule d'une recette.
    friend std::ostream& operator<<(std::ostream& stream, const Recipe& recipe) { 
        stream << "(" << recipe._id << ") ";
        for (const auto& m : recipe._materials) {
            stream << m << " ";
        }
        stream << "=> ";
        for (const auto& p : recipe._products) {
            stream << p << " ";
        }
        return stream; 
    }

    const size_t& get_id() { return _id; }

    const std::vector<std::string>& get_materials() const { return _materials; }
private:
    std::vector<std::string> _materials;
    std::vector<std::string> _products;
    size_t _id;
};
