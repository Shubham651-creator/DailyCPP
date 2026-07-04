#include <iostream>
#include "Flight.h"

static int n = 0;

int searchFlight(Flight flight[], int fNumber)
{
    for (int i = 0; i < n; i++)
    {
        if (fNumber == flight[i].getFlightNumber())
        {
            return i;
            break;
        }
    }

    std::cout << "Flight Number is not found.\n";
    return -1;
}

void modify(Flight flight[], int fNumber)
{
    int choice;

    std::cout << "Modify Menu: 1.Destination\t2.Distance\t3.exit\n";
    std::cin >> choice;
    std::string fDestionation;
    int fDistance;
    int index = searchFlight(flight, fNumber);
    switch (choice)
    {
    case 1:

        std::cout << "Enter modifyed destination name: ";
        std::cin >> fDestionation;
        flight[index].setFlightDestination(fDestionation);
        break;

    case 2:
        std::cout << "Enter modifyed distance in KM : ";
        std::cin >> fDistance;
        flight[index].setFlightDistance(fDistance);
        break;

    case 3:
        exit(0);
        break;
    }
}

void showMenu(Flight flight[])
{

    int choice;
    do
    {
        std::cout << "Menu: 1.Display\t2.Enter values\t3.search\t4.Modify\t5.Exit\n";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            // display/ showInfo()
            for (int i = 0; i < n; i++)
            {
                flight[i].showInfo();
            }
            break;

        case 2:
            // accept / feedInfo
            flight[n].feedInfo();
            n++;
            break;

        case 3:
            // search
            int fNumber;
            std::cout << "Enter searching flight number:";
            std::cin >> fNumber;
            if (searchFlight(flight, fNumber) != -1)
            {
                std::cout << "Flight is found, are you ready fly.\n";
            }
            break;

        case 4:
            // modify
            int fNumberModify;
            std::cout << "Enter Modifying flight number:";
            std::cin >> fNumberModify;
            if (searchFlight(flight, fNumberModify) != -1)
            {
                modify(flight, fNumberModify);
            }
            break;

        case 5:
            exit(0);
            break;
        }
    } while (1);
}

int main()
{

    Flight fight[100];
    showMenu(fight);

    return 0;
}