#pragma once

#include <ostream>
#include <vector>

class PhoneNumber {
public:
    PhoneNumber(int nb1, int nb2, int nb3, int nb4, int nb5)
        : _numbers { nb1, nb2, nb3, nb4, nb5 }
    {}

    bool is_valid() const;

    int operator[](int index) const;

    friend std::ostream& operator<<(std::ostream& stream, const PhoneNumber& phone);
private:
    std::vector<int> _numbers;
};


/*
class PhoneNumber {
public:
    PhoneNumber(int nb1, int nb2, int nb3, int nb4, int nb5)
        : _nb1 { nb1 }, 
        _nb2 { nb2 }, 
        _nb3 { nb3 }, 
        _nb4 { nb4 }, 
        _nb5 { nb5 }
    {}

    bool is_valid() const {
        return (_nb1 >= 0 && _nb1 <= 99) && (_nb2 >= 0 && _nb2 <= 99) 
        && (_nb3 >= 0 && _nb3 <= 99) && (_nb4 >= 0 && _nb4 <= 99) 
        && (_nb5 >= 0 && _nb5 <= 99);
    }

    int operator[](int index) const{
        switch(index) {
            case 0: return _nb1;
            case 1: return _nb2;
            case 2: return _nb3;
            case 3: return _nb4;
            case 4: return _nb5;
            default: return -1;
        }
    }

    friend std::ostream& operator<<(std::ostream& stream, PhoneNumber phone);
private:
    int _nb1;
    int _nb2;
    int _nb3;
    int _nb4;
    int _nb5;
};
*/

