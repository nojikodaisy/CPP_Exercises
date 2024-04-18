#pragma once
#include <array>
#include <vector>

template <typename Type, int Size>
class HybridArray
{
public:
    template <typename... Args>
    HybridArray(Args&&... args) {
        ((push_back(args)), ...);
    }

    // constexpr possible d'etre fait à la compilation
    constexpr static int static_size() {  
        return Size;
    }

    Type& push_back(Type val) {
        if (_size < Size) {
            _array[_size++] = std::move(val);
            return _array[_size - 1];
        } else if (_size == Size) {
            for(int i = 0; i < Size; i++) {
                _vec.push_back(_array[i]);
            }
        } 
        _size++;
        _vec.push_back(val);
        return _vec[_size - 1];
    }

    Type& operator[](int index) {
        //if (index < 0 || index > _size) return null;
        if (_size <= Size) {
            return _array[index];
        } else {
            return _vec[index];
        }
    }

    const Type& operator[](int index) const {
        if (_size <= Size) {
            return _array[index];
        } else {
            return _vec[index];
        }
    }

    int size() const { return _size; }
private:
    /* data */
    std::array<Type, Size> _array;
    int _size = 0;
    std::vector<Type> _vec;
    bool is_vec = (Size == 0);
};

template <typename Type>
class HybridArray<Type, 0> : public std::vector<Type>
{
    using std::vector<Type>::vector;
};


