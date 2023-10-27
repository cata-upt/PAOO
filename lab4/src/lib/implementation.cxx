#include <iostream>
#include <cstring>
#include "header.hpp"

Rectangle::Rectangle(int length, int width){
    this->length=length;
    this->width=width;
    std::cout<<"Shape created";
}

Rectangle::Rectangle(const Rectangle& shape){
    this->length=shape.length;
    this->width=shape.width;
    std::cout<<"Shape copied";
}

Rectangle::~Rectangle(){
    delete[] this;
    std::cout<<"Shape destroyed";
}
