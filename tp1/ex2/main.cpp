#include <iomanip>
#include <iostream>
#include <vector>
#include "Person.hpp"

int main() {
    int nb_persons;
    std::cout << "Nombre de personnes ? : ";
    std::cin >> nb_persons;
    auto tab_persons = std::vector<Person> {};
    std::string firstname;
    std::string surname;
    for (auto i = 0; i < nb_persons; i++) 
    {   
        std::cout << "Prénom ? : ";
        std::cin >> firstname;
        std::cout << "Nom ? : ";
        std::cin >> surname;
        tab_persons.emplace_back(Person(firstname, surname));
    }
    std::cout << "Les personnes sont ";
    for (auto j = 0; j < nb_persons; j++) 
    {
        std::cout << tab_persons[j].get_firstname() << " " << tab_persons[j].get_surname();
        if (j != nb_persons-1) 
        {
            std::cout << ", ";
        }
    }
    std::cout << "." << std::endl;
}