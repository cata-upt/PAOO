#pragma once
#include "address.hpp"
namespace UrbanAddress{

class UrbanAddress:protected Address{
    private:
        int unitNumber;
        int apartmentNumber; 
        char entrance;
    
    public:
        UrbanAddress();
        UrbanAddress(int, int, int,char, char*);
        UrbanAddress(const UrbanAddress& address);
        UrbanAddress(UrbanAddress&& address);
        ~UrbanAddress();
        UrbanAddress& operator=(const UrbanAddress&);
        UrbanAddress& operator=(UrbanAddress&&) noexcept;

        void print(const char*);
};

}