#pragma once
#include "document.hpp"

class excelDocument : public document{
    private:
        std::vector<std::vector<std::shared_ptr<char[]>>> excelContent;
        int rows,columns;
    public:
        excelDocument();
        excelDocument(int rows, int columns, const char* fileName);
        excelDocument(const char* filename, const std::vector<std::vector<std::shared_ptr<char[]>>> content);
        ~excelDocument();
        void addToDocument(int x, int y,const char* cellContent);
        void printDocument() override;
};
