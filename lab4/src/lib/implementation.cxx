#include <iostream>
#include <cstring>
#include "header.hpp"

Address::Address(int number, char* streetNameNew):number(number)
{
    streetName=new char[20];
    for(int i=0;i<20;i++){
        streetName[i]=streetNameNew[i];
    }
    std::cout<<"Address created.\n";
}

Address::Address(const Address &address):number(address.number)
{
    streetName = new char[20];
    for(int i=0;i<=20;i++){
        streetName[i]=address.streetName[i];
    }
    std::cout<<"Address copied.\n";
}

Address::Address(Address &&address):number(address.number)
{
    streetName = new char[20];
    for(int i=0;i<=20;i++){
        streetName[i]=address.streetName[i];
    }
    address.number=0;
    address.streetName=nullptr;
    std::cout<<"Address moved.\n";
}

Address::~Address()
{
    delete[] streetName;
    std::cout<<"Address destroyed\n";
}

void Address:: print(const char* variableName){
    std::cout<<"Variable: "<<variableName<<"\n"<<"Address number: "<<number<<"\nStreet name: "<<streetName<<"\n";
}
