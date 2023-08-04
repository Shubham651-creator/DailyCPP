#include <iostream>
#include "MyQueue.h"

MyQueue::~MyQueue()
{
    delete[] queue;
    std::cout<<"destructor\n";
}
