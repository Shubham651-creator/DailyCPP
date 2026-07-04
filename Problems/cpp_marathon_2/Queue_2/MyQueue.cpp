#include <iostream>
#include "MyQueue.h"

MyQueue::MyQueue()
{
    queueSize = 3;
    front = -1;
    rear = -1;
}

MyQueue::MyQueue(int size)
    : queueSize(size)
{
    front = -1;
    rear = -1;
}

MyQueue::~MyQueue()
{
    // delete queue;
}

bool MyQueue::isFull()
{
    if (rear == queueSize - 1)
        return true;
    else
        return false;
}

bool MyQueue::isEmpty()
{
    if (rear == front - 1)
        return true;
    else
        return false;
}

void MyQueue::push(int element)
{
    if (!isFull())
    {
        queue[++rear] = element;

        if (front == -1)
            front = 0;
    }
    else
    { /* code */
        throw OverflowException("Queue is full now\n");
    }
}

int MyQueue::pop()
{
    if (!isEmpty())
    {
        return queue[front++];
    }
    else
        throw UnderflowException("Queue is empty\n");
}

void MyQueue::display()
{
    std::cout << "Elements in queue are :\n ";
    for (int element = front; element < rear + 1; element++)
    {
        std::cout << queue[element] << "\t";
    }
    if (isEmpty())
        std::cout << "empty\n";
        
    std::cout << "\n";
}
