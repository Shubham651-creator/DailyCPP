#include <iostream>
#include "MyQueue.h"
#include "One.h"

int main()
{

    int size = 2;
    // MyQueue<char> queue(size);
    MyQueue<One> queue(size);

    One one1(20, "A"), one2(30, "B");

    try
    {
        // queue.enqueue('a');
        // queue.enqueue('b');
        // queue.enqueue('c');
        // queue.enqueue('d');
        // queue.enqueue('e');

        queue.enqueue(one1);
        queue.enqueue(one2);

        for (int i = 0; i < size; i++)
        {
            queue.dequeue();
            // std::cout << "element = " << queue.dequeue() << "\n";
        }

        std::cout << one1;
        std::cout << one2;

        // one1.display();
        // one2.display();

        // queue.dequeue();
        // queue.dequeue();
    }
    catch (OverflowException overObj)
    {
        std::cout << overObj.getMessage() << "\n";
    }
    catch (const char *msg)
    {
        std::cerr << "Error throw - " << msg << "\n";
    }

    return 0;
}