#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include "OverflowException.h"
#include "UnderflowException.h"

template<class dataType>
class MyQueue
{
private:
    dataType *queue;
    int front, rear, queueSize;

public:
    MyQueue()
    {
        queueSize = 3;
        front = -1;
        rear = -1;
        queue = new dataType[queueSize];
    }
    MyQueue(int size)
    {
        queueSize = size;
        front = -1;
        rear = -1;
        queue = new dataType[queueSize];
    }

    ~MyQueue();

    bool isEmpty()
    {
        if (rear + 1 == front)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (rear == queueSize - 1)
            return true;
        else
            return false;
    }

    void enqueue(dataType element)
    {
        if (!isFull())
        {
            queue[++rear] = element;
            if (front == -1)
                front = 0;
        }
        else
        {
            throw OverflowException("Queue is Full\n");
        }
    }

    dataType dequeue()
    {
        if (!isEmpty())
        {
            return queue[front++];
        }
        else
        {
            throw UnderflowException("Queue is empty\n");
        }
    }
};

template<class dataType>
MyQueue<dataType>::~MyQueue()
{
    delete[] queue;
    std::cout<<"called() destructor\n";
}

 
#endif // MYQUEUE_H
