#include <iostream>
#include "MyQueue.h"

int main()
{

    int size = 3;
    MyQueue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    for (int i = 0; i < size; i++)
    {
        std::cout << "element = " << queue.dequeue() << "\n";
    }
    return 0;
}