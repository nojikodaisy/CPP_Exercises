#pragma once

#include <string>
#include <memory>

class StringInstancePair
{
public :
    StringInstancePair(const std::string& str)
        : _str { str }, 
        instanceCounter { new InstanceCounter() }
    {}

    const std::string& get_str() const
    {
        return _str;
    }

    const InstanceCounter& get_instance_counter() const
    {
        return *instanceCounter.get();
    }

    StringInstancePair(StringInstancePair&& other) 
        : _str { std::move(other._str) },
        instanceCounter { std::move(other.instanceCounter) }
    {}

    StringInstancePair(const StringInstancePair& other) 
        : _str { std::move(other.get_str()) },
        instanceCounter { new InstanceCounter( *other.instanceCounter.get() ) }
    {}

private:
    std::string _str;
    std::unique_ptr<InstanceCounter> instanceCounter;
};
