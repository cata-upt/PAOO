#include "lib/header.hpp"
#include <iostream>


int main(){
    Rectangle rectangle1(1,3);
    std::cout<<"The area of the first shape is "<<rectangle1.calculateArea()<<"\n";
    std::cout<<"The perimeter of the first shape is "<<rectangle1.calculatePerimeter()<<"\n";
    Rectangle rectangle2= rectangle1;
    std::cout<<"The area of copied shape is "<<rectangle2.calculateArea()<<"\n";
    std::cout<<"The perimeter of copied shape is "<<rectangle2.calculatePerimeter()<<"\n";

    rectangle2.setLength(2);
    rectangle2.setWidth(4);
    Rectangle rectangle3=std::move(rectangle2);
    std::cout<<"The area of moved shape is "<<rectangle3.calculateArea()<<"\n";
    std::cout<<"The perimeter of moved shape is "<<rectangle3.calculatePerimeter()<<"\n";
    std::cout<<"The area of copied shape is "<<rectangle2.calculateArea()<<"\n";
    std::cout<<"The perimeter of copied shape is "<<rectangle2.calculatePerimeter()<<"\n";

    return 0;
}