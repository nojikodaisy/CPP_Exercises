#pragma once

#include "Department.hpp"

#include <list>
#include <string>

class HRSoftSystem
{
public:
    Department& add_department(const std::string& name)
    {
        return _departments.emplace_back(name);
    }

    void print_all_departments() 
    {
        for (auto dep : _departments)
        {
            std::cout << dep << std::endl;
        }
    }

    void print_all_employees() 
    {   
        std::cout << "Liste de tous les employés : " << std::endl;
        for (auto dep : _departments)
        {
            dep.print_employees();
        }
    }

    void remove_employee(Employee& employee) // MARCHE PAS
    {
        for (auto& dep : _departments)
        {   
            auto employees_list = dep.get_employees();
            for (auto emp : employees_list)
            {
                if (&emp == &employee)
                {
                    employees_list.remove(emp);
                    return;
                }
            }
        }
    }

private:
    std::list<Department> _departments;
};
