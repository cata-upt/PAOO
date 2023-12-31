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
        Address& operator=(const Address&);
        Address& operator=(Address&&) noexcept;

        virtual void print(const char*) const = 0;
};