#include <iomanip>
#include <iostream>

class Person
{
public:
    Person(std::string first_name, std::string surname);

    std::string get_firstname();

    std::string get_surname();
private:
    std::string _first_name;
    std::string _surname;
};