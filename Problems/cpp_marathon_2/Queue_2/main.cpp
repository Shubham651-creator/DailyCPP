#include <iostream>
#include "MyQueue.h"

// Menu driven
void showMenu(MyQueue queue, int Q_Size)
{
    int choice, element;
    do
    {
        std::cout << "Menu: 1.Push; 2.Pop; 3.Display; 4.exit; \t = ";
        std::cin >> choice;

        switch (choice)
        {
        case 1: // push the element

            // exception handling
            try
            {
                std::cout << "Enter queue element = ";
                std::cin >> element;
                queue.push(element);
            }
            catch (OverflowException msg)
            {
                std::cout << "Error : " << msg.getMessage() << "\n";
            }

            break;

        case 2: // Pop the element

            // exception handling
            try
            {
                std::cout << "The pop element is "
                          << queue.pop()
                          << "\n";
            }
            catch (UnderflowException msg)
            {
                std::cout << "error :" << msg.getMessage() << '\n';
            }

            break;

        case 3: // display the elements
            queue.display();
            break;

        case 4:
            exit(0);
            break;
        }
    } while (1);
}

int main()
{
    // size of queue
    int sizeQueue;
    std::cout << "Ente size of queue = ";
    std::cin >> sizeQueue;

    // creating a object with queue size as parameter
    MyQueue queue(sizeQueue);

    // Menu driven
    showMenu(queue, sizeQueue);

    return 0;
}