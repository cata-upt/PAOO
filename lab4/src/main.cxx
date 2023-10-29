#include "lib/header.hpp"
#include <iostream>
#include <string.h>

int main(){
    char *streetName= new char[20];
    strcpy(streetName,"Street1");

    Address address1(1,streetName);
    address1.print("address1");

    Address address2(address1);
    address2.print("address2");

    Address address3=std::move(address2);
    address3.print("address3");
    address2.print("address2");

    free(streetName);
    return 0;
}