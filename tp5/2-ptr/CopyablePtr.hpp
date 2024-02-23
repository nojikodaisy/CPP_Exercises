#pragma once
#include "Object.hpp"

class CopyablePtr
{
public:
    CopyablePtr() {}
    CopyablePtr(int value) 
    : _obj { new Object { value } }
    {}

    CopyablePtr(const CopyablePtr& other) 
    :   _obj { (other._obj != nullptr) ? new Object(*other._obj) : nullptr }
    {}

    CopyablePtr(CopyablePtr&& other) 
    : _obj { std::move(other._obj) }
    {
        other._obj = nullptr;
    }

    ~CopyablePtr() {
        delete _obj;
    }

    bool operator==(std::nullptr_t other) {
        return (_obj == other);
    }
    
    const Object& operator*() const {
        return *_obj;
    }

    const CopyablePtr& operator=(const CopyablePtr& other) {
        if (this != &other) {
            if (_obj != nullptr) {
                delete _obj;
            }
            _obj = new Object(*other._obj);
        }
        return *this;
    }

    CopyablePtr& operator=(CopyablePtr&& other) {
        if (this != &other) {
            if (_obj != nullptr) {
                delete _obj;
            }
            _obj = std::move(other._obj);
            other._obj = nullptr;
        }
        return *this;
    }

    void operator=(std::nullptr_t) {
        delete _obj;
        _obj = nullptr;
    }


private:
    Object *_obj = nullptr;
};
