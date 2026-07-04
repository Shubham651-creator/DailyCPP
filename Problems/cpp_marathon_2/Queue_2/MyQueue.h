#ifndef MYQUEUE_H
#define MYQUEUE_H

#include"OverflowException.h"
#include"UnderflowException.h"

class MyQueue
{
private:
    int *queue;
    int queueSize, front, rear;  

public:
    // default constructor
    MyQueue();

    // parameterized constructor
    MyQueue(int size);

    // destructor
    ~MyQueue();

    //check queue is full or not
    bool isFull();

    //check queue is empty or not
    bool isEmpty();

    //Enqueue operation - push element in queue
    void push(int element);

    //Dequeue opeation - pop element in queue
    int pop();

    //display the queue elements
    void display();
};

#endif // MYQUEUE_H
