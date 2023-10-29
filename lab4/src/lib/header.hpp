#pragma once

class Address{
    private:
        int number;
        char* streetName;
    
    public:
        Address(int, char*);
        Address(const Address& address);
        Address(Address&& address);
        ~Address();

        void print(const char*);
};