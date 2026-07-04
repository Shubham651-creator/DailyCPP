#include <iostream>
#include "Flight.h"

int searchFlight(std::string flight_number, Flight flight[], int numberOfFlight)
{
    for (int count = 0; count < numberOfFlight; count++)
    {
        if (flight_number == flight[count].getFightNumber())
        {
            std::cout << "Flight Number " << flight[count].getFightNumber() << " is found.\n";
            return count;
        }
    }
    std::cout << "Your flight number is not found.Please enter available flights\n";
    return -1;
}

void showMenu(Flight flight[], int numberOfFlight)
{

    int choice, booking = 0, fare;
    std::string flight_number;
    do
    {
        std::cout << "ENTER CHOICE = 1.book flight; 2.search flight; 3.calculate flight fare; 4.display; 5.Exit\n";
        std::cin >> choice;

        switch (choice)
        {
        case 1: // book flight using flight number
            flight[booking].bookFlight();
            booking++;
            break;

        case 2: // search flight using flight number
            std::cout << "Enter flight number for searching :";
            std::cin >> flight_number;
            searchFlight(flight_number, flight, numberOfFlight);
            break;

        case 3: // calculate flight fare according to destination
            fare = flight[booking].calculateFare();
            std::cout << "The total fare will be Rs." << fare << "\n";
            break;

        case 4: // display the airline information
            for (int flightbook = 0; flightbook < booking; flightbook++)
            {
                flight[flightbook].display();
            }
            break;
        case 5:
            exit(0);
            break;
        }

    } while (1);
}

// client code
int main()
{
    int numberOfFlight = 5;
    Flight flight[numberOfFlight];
    showMenu(flight, numberOfFlight);
    return 0;
}