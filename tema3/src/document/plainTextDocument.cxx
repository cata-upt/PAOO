#include "plainTextDocument.hpp"

plainTextDocument::plainTextDocument()
{
    sem_init(&documentSemaphore, 0, 1);
    fileName="";
    documentContent=std::shared_ptr<char[]>(new char[1]);
}

plainTextDocument::plainTextDocument(const char* fileName)
{
    sem_init(&documentSemaphore, 0, 1);
    this->fileName=fileName;
    documentContent=std::shared_ptr<char[]>(new char[1]);
}

plainTextDocument::plainTextDocument(const char *filename,const char *content)
{
    sem_init(&documentSemaphore, 0, 1);
    this->fileName=fileName;
    documentContent=std::shared_ptr<char[]>(new char[strlen(content)+1]);
    strcpy(documentContent.get(),content);
}

plainTextDocument::~plainTextDocument()
{
    sem_destroy(&documentSemaphore);
    std::cout<<"This is the document destructor"<<std::endl;
}

void plainTextDocument::addToDocument(const char* lineContent)
{
    sem_wait(&documentSemaphore);
    strcat(documentContent.get(),lineContent);
    sem_post(&documentSemaphore);
}

void plainTextDocument::printDocument()
{
    std::lock_guard<std::mutex> lock(fileMutex);
    std::cout<<documentContent<<std::endl;
}
