#pragma once

#include <list>
#include <ostream>
#include <string>
#include <iostream>

class Employee
{
public:
    Employee(const std::string& name, unsigned int salary)
        : _name { name }, _salary { salary }
    {}

    void add_subordinate(Employee& subordinate)
    {
        _subordinates.emplace_back(&subordinate);
    }

    void print_subordinates() {
        std::cout << "Liste des subordonnées : " << std::endl;
        for (auto sub : _subordinates)
        {
            std::cout << *sub << std::endl;
        }
    }

    friend std::ostream& operator<<(std::ostream&, const Employee&);

    bool operator==(const Employee& other) const
    {
        return _name == other._name && _salary == other._salary && _subordinates == other._subordinates; 
    }

private:
    std::string _name;
    unsigned int _salary = 0;
    std::list<Employee*> _subordinates;
};

inline std::ostream& operator<<(std::ostream& stream, const Employee& employee)
{
    const auto is_manager = !employee._subordinates.empty();
    return stream << employee._name
                  << " (salary: " << employee._salary
                  << "| manager: " << (is_manager ? "yes" : "no")
                  << ")";
}
