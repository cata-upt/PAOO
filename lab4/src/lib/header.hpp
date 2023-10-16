#pragma once

class Shape{
    private:
        int length;
        int width;
    
    public:
        Shape(int, int);
        Shape(const Shape&);
        ~Shape();
}