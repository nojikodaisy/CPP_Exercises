#include <iomanip>
#include <iostream>

int main()
{
    std::cout << "Entre ton nom: ";

    std::string name = "";
    std::cin >> name;
    std::cout << "Bonjour " << name << std::endl;

    return 0;
}
