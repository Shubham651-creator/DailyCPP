#include <iostream>
#include "Flight.h"

flightClass Flight::acceptFlightClass(int userClassInput)
{
    if (userClassInput == 1)
        return flightClass::ECONOMY;
    if (userClassInput == 2)
        return flightClass::PREMIUMECONOMY;
    if (userClassInput == 3)
        return flightClass::BUSINESS;
    if (userClassInput == 4)
        return flightClass::FIRSTCLASS;

    return flightClass::BUSINESS;
}

Flight::Flight()
{
    flightNumber = "TATAairlines";
    fClass = flightClass::FIRSTCLASS;
    ticketsAvailable = 520;
    ticketIssued = 2;
    fromPlace = "Mumbai";
    toPlace = "Ahemdabad";
}

Flight::Flight(std::string flight_number, flightClass f_class, int tickets_avilable, int ticket_issued, std::string to_place)
{
    flightNumber = flight_number;
    fClass = f_class;
    ticketsAvailable = tickets_avilable;
    ticketIssued = ticket_issued;
    toPlace = to_place;
} 

void Flight::display()
{
    std::cout << "The Airline details : \n"<< "Flight Number:" << flightNumber<< "\navilable tickets:" << ticketsAvailable - ticketIssued << "\nissued tickets:" << ticketIssued<< "\nfrom place:" << fromPlace << "\nto place:" << toPlace << "\n\n";
   
}

void Flight::bookFlight()
{
    std::cout << "Book your flight from Mumbai to ....\n"<< "Enter your flight number:";
    std::cin >> flightNumber;

    std::cout << "Enter your flight class : 1.economy; 2.premium economy; 3.business; 4.first class\n";
    int userClassInput;
    std::cin >> userClassInput;
    fClass = acceptFlightClass(userClassInput);

    std::cout << "Enter how many you want to ticket issusing : ";
    std::cin >> ticketIssued;

    std::cout << "Enter destination from Mumbai: ";
    std::string destination;
    if (destination == "goa" || destination == "delhi" || destination == "bangalore" || destination == "ahmedabad")
    {
        std::cin >> toPlace;
    }
    else
    {
        std::cout << "Your destination is not available\n";
    }

    std::cout << "\n\n";
}

int Flight::calculateFare()
{
    std::string destination;
    std::cout << "Enter your destination from Mumbai :";
    std::cin >> destination; 

    if (destination == "goa")
        return 4470;
    if (destination == "delhi")
        return 4181;
    if (destination == "bangalore")
        return 2170;
    if (destination == "ahmedabad")
        return 1752;

    return 0;
}
