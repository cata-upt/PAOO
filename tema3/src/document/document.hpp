#pragma once 
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <thread>
#include <semaphore.h>
#include <mutex>
#include <string.h>

class document{
    protected:
        std::mutex fileMutex;
        std::string fileName;
        sem_t documentSemaphore;
    public:
        ~document() = default;
        virtual void printDocument() = 0;
};