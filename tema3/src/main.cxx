#include "document/plainTextDocument.hpp"
#include "document/excelDocument.hpp"

int main(){
    plainTextDocument textDocument("text.txt");
    excelDocument excelDoc(5,5,"excel.doc");

    std::thread thread_plain([&textDocument](){
        textDocument.addToDocument("textforDocument");
    });
    std::thread thread_plain2([&textDocument](){
        textDocument.addToDocument("textforDocument");
    });
    
    std::thread thread_excel1([&excelDoc](){
        excelDoc.addToDocument(0,1,"A2");
    });
    std::thread thread_excel2([&excelDoc](){
        excelDoc.addToDocument(1,1,"B2");
    });

    thread_plain.join();
    thread_plain2.join();
    thread_excel1.join();
    thread_excel2.join();

    textDocument.printDocument();
    excelDoc.printDocument();

}