#pragma once

class Rectangle{
    private:
        int length;
        int width;
    
    public:
        Rectangle(int, int);
        Rectangle(const Rectangle& rectangle);
        Rectangle(Rectangle&& rectangle);
        ~Rectangle();

        int calculateArea();
        int calculatePerimeter();
        void setLength(int);
        void setWidth(int);
};