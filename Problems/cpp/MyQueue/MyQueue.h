#ifndef MYQUEUE_H
#define MYQUEUE_H

class MyQueue
{
private:
    int *queue;
    int front, rear, queueSize;

public:
    MyQueue(int size)
    {
        queueSize = size;
        front = rear = -1;
    }
    MyQueue()
    {
        queueSize = 3;
        front = rear = -1;
    }
    ~MyQueue();

    void enqueue(int element)
    {
        queue[++rear] = element;
        if (front == -1)
            front++;
    }

    int dequeue()
    {
        return queue[front++];
    }
};

#endif // MYQUEUE_H
