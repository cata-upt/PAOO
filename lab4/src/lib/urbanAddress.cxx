#include "iostream"
#include <cstring>
#include "urbanAddress.hpp"

UrbanAddress::UrbanAddress::UrbanAddress():Address()
{
    unitNumber=0;
    apartmentNumber=0;
    entrance='0';
    printf("Urban address created.\n");
}

UrbanAddress::UrbanAddress::UrbanAddress(int streetNumber, int unitNumber, int apartmentNumber,char entrance, char *streetName):unitNumber(unitNumber), apartmentNumber(apartmentNumber),entrance(entrance),Address(streetNumber,streetName)
{
    std::cout<<"Urban address created.\n";
}

UrbanAddress::UrbanAddress::UrbanAddress(const UrbanAddress &address):unitNumber(address.unitNumber),apartmentNumber(address.apartmentNumber),entrance(entrance),Address(address.streetNumber,address.streetName)
{
    printf("Urban address copied.\n");
}

UrbanAddress::UrbanAddress::UrbanAddress(UrbanAddress &&address):unitNumber(address.unitNumber),apartmentNumber(address.apartmentNumber),entrance(entrance),Address(address.streetNumber,address.streetName)
{
    address.streetNumber=0;
    address.unitNumber=0;
    address.apartmentNumber=0;
    address.entrance=0;
    address.streetName=nullptr;
    printf("Urban address moved.\n");
}

UrbanAddress::UrbanAddress::~UrbanAddress()
{
    printf("Urban address destroyed!\n");
}

UrbanAddress::UrbanAddress &UrbanAddress::UrbanAddress::operator=(const UrbanAddress &address)
{
    if(this != &address){
        Address::operator=(address);
        unitNumber=address.unitNumber;
        apartmentNumber=address.apartmentNumber;
        entrance=address.entrance;
        std::cout<<"Urban address copy assignment called.\n";
    }
    return *this;
}

UrbanAddress::UrbanAddress &UrbanAddress::UrbanAddress::operator=(UrbanAddress &&address) noexcept
{
    if(this != &address){
        Address::operator=(std::move(address));
        unitNumber=address.unitNumber;
        apartmentNumber=address.apartmentNumber;
        entrance=address.entrance;

        address.unitNumber=0;
        address.apartmentNumber=0;
        address.entrance=0;
        std::cout<<"Urban address move assignment called.\n";
    }
    return *this;
}

void UrbanAddress::UrbanAddress::print(const char *variableName)
{
    std::cout<<"Variable: "<<variableName<<" is an urban Address."<<"\n{\n"<<"Address number: "<<streetNumber<<"\n"<<"Unit number: "<<this->unitNumber<<"\n";
    std::cout<<"Entrance: "<<entrance<<"\n"<<"Apartment Number: "<<this->apartmentNumber<<"\n"<<"Street name: "<<streetName<<"\n}\n";
}
