#include "lib/address.hpp"
#include "lib/ruralAddress.hpp"
#include "lib/urbanAddress.hpp"
#include <iostream>
#include <string.h>

int main(){
    char *streetName= new char[20];
    strcpy(streetName,"Street1");

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
    urbanAddress1.sendMail(ruralAddress1);
    urbanAddress1.sendMail(urbanAddress2);
    free(streetName);
    return 0;
}