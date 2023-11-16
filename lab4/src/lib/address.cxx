#include <iostream>
#include <cstring>
#include "address.hpp"

Address::Address(){
    streetNumber=0;
    strcpy(this->streetName,"");
    std::cout<<"Address created.\n";
}

Address::Address(int streetNumber, char* streetName):streetNumber(streetNumber)
{
    this->streetName=new char[20];
    strcpy(this->streetName, streetName);
    std::cout<<"Address created.\n";
}

Address::Address(const Address &address):streetNumber(address.streetNumber)
{
    this->streetName=new char[20];
    strcpy(this->streetName,address.streetName);
    std::cout<<"Address copied.\n";
}

Address::Address(Address &&address):streetNumber(address.streetNumber)
{
    this->streetName=new char[20];
    strcpy(this->streetName, address.streetName);
    address.streetNumber=0;
    address.streetName=nullptr;
    std::cout<<"Address moved.\n";
}

Address::~Address()
{
    delete[] streetName;
    std::cout<<"Address destroyed\n";
}

void Address:: print(const char* variableName){
    if(this!=nullptr && this->streetName!=nullptr){
        std::cout<<"Variable: "<<variableName<<"\n{\n"<<"Address number: "<<streetNumber<<"\n"<<"Street name: "<<streetName<<"\n}\n";
    }else{
        std::cout<<"Variable: "<<variableName<<"\n{\n"<<"Address not found"<<"\n}\n";
    }
}
