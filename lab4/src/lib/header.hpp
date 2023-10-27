#pragma once

class Rectangle{
    private:
        int length;
        int width;
    
    public:
        Rectangle(int, int);
        Rectangle(const Rectangle&);
        ~Rectangle();
};