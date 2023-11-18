#include "lib/address.hpp"
#include "lib/ruralAddress.hpp"
#include "lib/urbanAddress.hpp"
#include <iostream>
#include <string.h>

int main(){
    char *streetName= new char[20];
    strcpy(streetName,"Street1");

    Address address1(1,streetName);
    address1.print("address1");

    Address address2(address1);
    address2.print("address2");

    Address address3;
    address3=std::move(address2);

    RuralAddress::RuralAddress ruralAddress1(1, streetName);
    ruralAddress1.print("ruralAddress1");

    RuralAddress::RuralAddress ruralAddress2;
    ruralAddress2=ruralAddress1;
    ruralAddress2.print("ruralAddress2");

    UrbanAddress::UrbanAddress urbanAddress1(1,1,1,'A',streetName);
    urbanAddress1.print("urbanAddress1");

    UrbanAddress::UrbanAddress urbanAddress2;
    urbanAddress2=std::move(urbanAddress1);
    urbanAddress2.print("UrbanAddress2");

    free(streetName);
    return 0;
}