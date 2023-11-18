#include <iostream>
#include <cstring>
#include "address.hpp"

Address::Address(){
    streetNumber=0;
    this->streetName=new char[20];
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
    std::cout<<"Address destroyed!\n";
}

Address &Address::operator=(const Address &address)
{
    if(this != &address){
        delete[] streetName;
        streetNumber=address.streetNumber;
        streetName=new char(strlen(address.streetName)+1);
        strcpy(streetName,address.streetName);
        std::cout<<"Address copied through operator.\n";
    }
    return *this;
}

Address &Address::operator=(Address &&address) noexcept
{
    if(this!= &address){
        delete[] streetName;
        streetNumber=address.streetNumber;
        streetName=new char(strlen(address.streetName)+1);
        strcpy(streetName, address.streetName);
        std::cout<<"Address moved through operator.\n";
    }
    return *this;
}
