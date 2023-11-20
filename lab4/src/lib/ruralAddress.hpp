#pragma once
#include "address.hpp"
#include <iostream>
namespace RuralAddress{
class RuralAddress: public Address{
    
    public:
        RuralAddress()=default;

        using Address::Address;

        ~RuralAddress();

        void print(const char*) const override;
        virtual void sendMail(const RuralAddress&) const;
        virtual int getStreetNumber() const;
        virtual char* getStreetName() const;
};
}