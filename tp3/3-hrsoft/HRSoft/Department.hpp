#pragma once

#include "Employee.hpp"

#include <list>
#include <string>
#include <iostream>

class Department
{
public:
    Department(const std::string& name)
        : _name { name }
    {}

    Employee& add_employee(const std::string& name, unsigned int salary, Employee* manager)
    {
        auto& employee = _employees.emplace_back(name, salary);

        if (manager != nullptr)
        {
            manager->add_subordinate(employee);
        }

        return employee;
    }

    void print_employees() 
    {
        for (auto employee : _employees)
        {
            std::cout << employee << std::endl;
        }
    }

    std::list<Employee> get_employees() const
    {
        return _employees;
    }

    friend std::ostream& operator<<(std::ostream&, const Department& dep);

private:
    std::string _name;
    std::list<Employee> _employees;
};

inline std::ostream& operator<<(std::ostream& stream, const Department& dep)
{
    return stream << "Département : " << dep._name;
}