#include "excelDocument.hpp"

excelDocument::excelDocument()
{
    sem_init(&documentSemaphore, 0, 1);
    rows=10;
    columns=10;
    fileName="";
    excelContent.resize(rows,std::vector<std::shared_ptr<char[]>>(columns,nullptr));
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            excelContent[i][j]=std::shared_ptr<char[]>(new char[1]);
            strcpy(excelContent[i][j].get(),"*");
        }
    }
}

excelDocument::excelDocument(int rows, int columns, const char* fileName):document(),rows(rows),columns(columns)
{
    sem_init(&documentSemaphore, 0, 1);
    this->fileName=fileName;
    excelContent.resize(rows,std::vector<std::shared_ptr<char[]>>(columns,nullptr));
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            excelContent[i][j]=std::shared_ptr<char[]>(new char[1]);
            strcpy(excelContent[i][j].get(),"*");
        }
    }
}

excelDocument::excelDocument(const char* filename, const std::vector<std::vector<std::shared_ptr<char[]>>> content):document(),rows(content.size()),columns(content[0].size())
{
    sem_init(&documentSemaphore, 0, 1);
    this->fileName=fileName;
    excelContent.resize(rows,std::vector<std::shared_ptr<char[]>>(columns,nullptr));
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            excelContent[i][j]=std::shared_ptr<char[]>(new char[strlen(content[i][j].get())]);
            strcpy(excelContent[i][j].get(),"*");
        }
    }
}

excelDocument::~excelDocument()
{
    sem_destroy(&documentSemaphore);
    std::cout<<"This is the document destructor"<<std::endl;
}

void excelDocument::addToDocument(int x, int y,const char* cellContent)
{
    if(x>=0 && x<excelContent[0].size() && y>=0 && y<excelContent.size()){
        sem_wait(&documentSemaphore);
        strcpy(excelContent[x][y].get(),cellContent);
        sem_post(&documentSemaphore);
    }else{
        std::cout<<"One or both indexes are wrong"<<std::endl;
    }
}

void excelDocument::printDocument()
{
    std::lock_guard<std::mutex> lock(fileMutex);
    for(const auto& row: excelContent){
        for(const auto& cell: row){
            std::cout<<cell<<"\t";
        }
        std::cout<<std::endl;
    }
}
