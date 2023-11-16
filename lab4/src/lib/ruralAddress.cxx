#include "ruralAddress.hpp"

void RuralAddress::RuralAddress::print(const char* variableName){
    std::cout<<"Variable: "<<variableName<<" is a rural Address."<<"\n{\n"<<"Address number: "<<Address::streetNumber<<"\nStreet name: "<<Address::streetName<<"\n}\n";
}