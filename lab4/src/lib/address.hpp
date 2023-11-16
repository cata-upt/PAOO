#pragma once

class Address{
    protected:
        int streetNumber;
        char* streetName;
    
    public:
        Address();
        Address(int, char*);
        Address(const Address& address);
        Address(Address&& address);
        ~Address();

        void print(const char*);
};