#pragma once
#include "ruralAddress.hpp"
namespace UrbanAddress{

class UrbanAddress:public RuralAddress::RuralAddress{
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

        void print(const char*) const override;
        void sendMail(const UrbanAddress&);
        void sendMail(const RuralAddress&) const override;
};

}