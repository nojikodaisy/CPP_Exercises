#include "ProgramData.hpp"


void ProgramData::add_material(std::string name)
{
    _materials.emplace_back(std::make_unique<Material>(std::move(name)));
}

void ProgramData::get_materials(std::vector<const Material*>& materials) const
{
    for(const auto& m : _materials) {
        materials.emplace_back(m.get());
    }
}

void ProgramData::register_recipe(std::vector<std::string> materials, std::vector<std::string> products)
{
    _recipes.emplace_back(Recipe(std::move(materials), std::move(products)));
    std::cout << "Recipe " << _recipes.back() << "has been registered" << std::endl;
}

bool contains(const std::vector<std::unique_ptr<Material>>& vec, const std::string &str)
{
    for (const auto& elem : vec)
    {   
        if (elem->get_name() == str)
        {
            return true;
        }
    }

    return false;
}

void ProgramData::collect_doable_recipes(std::vector<const Recipe*>& recipes) const
{   
    bool OK = true;
    for (const auto& r : _recipes) {
        for(const auto& m : r.get_materials()) {
            if (!contains(_materials, m)) {
                OK = false;
            }
        }
        if (OK) {
            recipes.emplace_back(&r);
        }
        OK = true;
    }
}

ProductionResult ProgramData::produce(size_t recipe_id)
{
    ProductionResult result;
    Recipe* recipe = nullptr;
    for (const auto& r : _recipes) {
        if (r.get_id() == recipe_id) {
            recipe = r;
            for (const auto& m : r.get_materials()) {
                if (!contains(_materials, m)) {
                    result.missing_materials.emplace_back(m);
                }
            }
        }
    }
    if (result.missing_materials.size == 0) {
        // enlève les matériaux requis
        // on ajoute les recipe.product dans material
    }

    result.recipe = recipe;
    return result;
}