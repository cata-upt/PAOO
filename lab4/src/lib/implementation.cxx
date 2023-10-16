#include <iostream>
#include <cstring>
#include "header.hpp"

Shape::Shape(int length, int width){
    this->length=length;
    this->width=width;
    std::cout<<"Shape created";
}

Shape::Shape(const Shape& shape){
    this->length=shape.length;
    this->width=shape.width;
    std::cout<<"Shape copied";
}

Shape::Shape(){
    delete[] this->length;
    delete[] this->width;
    std::cout<<"Shape destroyed";
}