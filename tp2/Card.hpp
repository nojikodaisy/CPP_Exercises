#include <iomanip>
#include <iostream>

class Card
{
public:
    Card(unsigned int value, std::string color);

    unsigned int get_value() const;

    const std::string& get_color() const;

    void print() const;

    bool operator==(const Card& c1) const;

    bool operator<(const Card& c1) const;

    friend std::ostream& operator<<(std::ostream& stream, const Card& card);

private:
    unsigned int _value;
    std::string _color;
};