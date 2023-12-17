#pragma once
#include "document.hpp"

class plainTextDocument : public document{
    private:
        std::shared_ptr<char[]> documentContent;
    public:
        plainTextDocument();
        plainTextDocument(const char* fileName);
        plainTextDocument(const char* filename, const char* content);
        ~plainTextDocument();
        void addToDocument(const char* lineContent);
        void printDocument() override;
};
