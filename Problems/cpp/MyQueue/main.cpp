#include <iostream>
#include "MyQueue.h"

int main()
{

    int size = 5;
    MyQueue queue(size);

    try
    {
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        queue.enqueue(40);
        queue.enqueue(50);

        for (int i = 0; i < size; i++)
        {
            std::cout << "element = " << queue.dequeue() << "\n";
        }
    }
    catch(OverflowException overObj){
        std::cout<<overObj.getMessage()<<"\n";
    }
    catch (const char *msg)
    {
        std::cerr <<"Error throw - " <<msg << "\n";
    }

    return 0;
}