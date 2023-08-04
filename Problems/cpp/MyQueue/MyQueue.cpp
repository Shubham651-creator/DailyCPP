#include <iostream>
#include "MyQueue.h"

MyQueue::~MyQueue()
{
    delete[] queue;
    std::cout<<"destructor\n";
}

// void MyQueue::enqueue(int element)
// {
//     if (!isFull())
//     {
//         queue[++rear] = element;
//         if (front == -1)
//             front = 0;
//     }
//     else
//     {
//         throw OverflowException("Queue is Full\n");
//     }
// }
