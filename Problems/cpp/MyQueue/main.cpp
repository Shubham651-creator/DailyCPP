#include <iostream>
#include "MyQueue.h"

int main()
{

    int size = 2;
    //MyQueue<char> queue(size);
    MyQueue<std::string> queue(size);

    try
    {
        // queue.enqueue('a');
        // queue.enqueue('b');
        // queue.enqueue('c');
        // queue.enqueue('d');
        // queue.enqueue('e');

        queue.enqueue("shuba");
        queue.enqueue("Awale");

        for (int i = 0; i < size; i++)
        {
            std::cout << "element = " << queue.dequeue() << "\n";
        }
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