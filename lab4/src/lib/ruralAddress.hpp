#pragma once
#include "address.hpp"
#include <iostream>
namespace RuralAddress{
class RuralAddress: public Address{
    
    public:
        RuralAddress()=default;

        using Address::Address;

        void print(const char*);
};
}