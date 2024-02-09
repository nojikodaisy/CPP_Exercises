#include "PhoneNumber.hpp"
#include <ostream>

bool PhoneNumber::is_valid() const {
    for (int i = 0; i < 5; i++) {
        if (_numbers[i] < 0 || _numbers[i] > 99) {
            return false;
        }
    }
    return true;
}

int PhoneNumber::operator[](int index) const{
    if (index >= 0 && index <= 4) return _numbers[index];
    return -1;
}

std::ostream& operator<<(std::ostream& stream, const PhoneNumber& phone) 
{   

    for (int i = 0; i < 5; i++) {
        stream << ((phone._numbers[i] > 10) ? "" : "0") << phone._numbers[i];
    }
    return stream;
}