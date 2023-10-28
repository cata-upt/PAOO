#include <iostream>
#include <cstring>
#include "header.hpp"

Rectangle::Rectangle(int length, int width):length(length),width(width){
    std::cout<<"Shape created\n";
}

Rectangle::Rectangle(const Rectangle& rectangle):length(rectangle.length),width(rectangle.width){
    std::cout<<"Shape copied\n";
}

Rectangle::Rectangle(Rectangle &&rectangle):length(rectangle.length),width(rectangle.width){
    std::cout<<"Shape moved\n";
}

Rectangle::~Rectangle(){
    std::cout<<"Shape destroyed\n";
}

int Rectangle::calculateArea(){
    return this->length*this->width;
}

int Rectangle::calculatePerimeter(){
    return 2*(this->length+this->width);
}

void Rectangle::setLength(int legth)
{
    this->length=legth;
    std::cout<<"The length of the shape was changed to: "<<legth<<"\n";
}

void Rectangle::setWidth(int width)
{
    this->width=width;
    std::cout<<"The width of the shape was changed to: "<<width<<"\n";
}
