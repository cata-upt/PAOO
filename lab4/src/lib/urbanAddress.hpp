#pragma once
#include "address.hpp"
namespace UrbanAddress{

class UrbanAddress:public Address{
    private:
        int streetNumber;
        int unitNumber;
        int apartmentNumber; 
        char entrance;
        char* streetName;
    
    public:
        UrbanAddress();
        UrbanAddress(int, int, int,char, char*);
        UrbanAddress(const UrbanAddress& address);
        UrbanAddress(UrbanAddress&& address);
        ~UrbanAddress();

        void print(const char*);
};

}