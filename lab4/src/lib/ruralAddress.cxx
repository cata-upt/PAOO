#include "ruralAddress.hpp"

RuralAddress::RuralAddress::~RuralAddress()
{
    std::cout<<"Rural address destroyed!\n";
}

void RuralAddress::RuralAddress::print(const char *variableName) const 
{
    std::cout<<"Variable: "<<variableName<<" is a rural Address."<<"\n{\n"<<"Address number: "<<Address::streetNumber<<"\nStreet name: "<<Address::streetName<<"\n}\n";
}

void RuralAddress::RuralAddress::sendMail(const RuralAddress& address) const
{
    std::cout<<"Sending mail to rural address: "<<address.streetNumber<<" "<<address.streetName;
}

int RuralAddress::RuralAddress::getStreetNumber() const
{
    return this->streetNumber;
}

char *RuralAddress::RuralAddress::getStreetName() const
{
    return this->streetName;
}
