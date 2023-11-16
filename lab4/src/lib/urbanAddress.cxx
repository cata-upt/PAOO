#include "iostream"
#include <cstring>
#include "urbanAddress.hpp"

UrbanAddress::UrbanAddress::UrbanAddress()
{
    this->streetName=new char[20];
    streetNumber=0;
    unitNumber=0;
    apartmentNumber=0;
    strcpy(this->streetName,"");
    printf("Urban address created.\n");
}

UrbanAddress::UrbanAddress::UrbanAddress(int streetNumber, int unitNumber, int apartmentNumber,char entrance, char *streetName):unitNumber(unitNumber), apartmentNumber(apartmentNumber),entrance(entrance),Address(streetNumber,streetName)
{
    std::cout<<"Urban address created.\n";
}

UrbanAddress::UrbanAddress::UrbanAddress(const UrbanAddress &address):streetNumber(address.streetNumber),unitNumber(address.unitNumber),apartmentNumber(address.apartmentNumber)
{
    this->streetName=new char[20];
    strcpy(this->streetName,address.streetName);
    printf("Urban address copied.\n");
}

UrbanAddress::UrbanAddress::UrbanAddress(UrbanAddress &&address):streetNumber(address.streetNumber),unitNumber(address.unitNumber),apartmentNumber(address.apartmentNumber)
{
    this->streetName=new char[20];
    strcpy(this->streetName,address.streetName);
    address.streetNumber=0;
    address.unitNumber=0;
    address.apartmentNumber=0;
    address.streetName=nullptr;
    printf("Urban address moved.\n");
}

UrbanAddress::UrbanAddress::~UrbanAddress()
{
    delete[] streetName;
    printf("Urban address destroyed.\n");
}

void UrbanAddress::UrbanAddress::print(const char *variableName)
{
    std::cout<<"Variable: "<<variableName<<" is an urban Address."<<"\n{\n"<<"Address number: "<<streetNumber<<"\n"<<"Unit number: "<<this->unitNumber<<"\n";
    std::cout<<"Entrance: "<<entrance<<"\n"<<"Apartment Number: "<<this->apartmentNumber<<"\n"<<"Street name: "<<streetName<<"\n}\n";
}
