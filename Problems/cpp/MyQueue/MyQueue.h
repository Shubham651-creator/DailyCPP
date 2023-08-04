#ifndef MYQUEUE_H
#define MYQUEUE_H

class MyQueue
{
private:
    int *queue;
    int front, rear, queueSize;

public:
    MyQueue()
    {
        queueSize = 3;
        front = -1;
        rear = -1;
        queue = new int[queueSize];
    }
    MyQueue(int size)
    {
        queueSize = size;
        front = -1;
        rear = -1;
        queue = new int[queueSize];
    }

    ~MyQueue();

    bool isEmpty()
    {
        if (rear+1 == front)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (rear == queueSize-1)
            return true;
        else
            return false;
    }

    void enqueue(int element)
    {
        if (!isFull())
        {
            queue[++rear] = element;
            if (front == -1)
                front = 0;
        }
        else
        {
            throw "Queue is Full\n";
        }
    }

    int dequeue()
    {
        if (!isEmpty())
        {
            return queue[front++];

        }
        else
        {
            throw "Queue is empty\n";
        }
    }
};

#endif // MYQUEUE_H
