#include <iostream>
#include "Train.h"

// global array of distance
int dist[5] = {1720, 1205, 980, 2100, 300};

// global array of destination
std::string destination[5] = {"kolhapur", "Surat", "Nagpur", "Ranchi", "dehradun"};

// static variable for train initializing train number
int Train ::availableASeats = 450;

// default constructor
Train::Train()
{
    trainName = "Dakshin";
    trainNumber = 1001;
    fromplace = "New Delhi";
    toPlace = "kolhapur";
    distance = 1720;
    class_Type = TravelClass::AC3ECONOMY;
    // display();
}
// end of default constructor

// function to display train details
void Train::display()
{
    std::cout << "\nTrain number: " << trainNumber << ", Train name: " << trainName << ", Available seats:" << availableASeats;
    std::cout << "\nRoute : ";
    std::cout << "\n"
              << fromplace << " to " << toPlace;
    //std::cout<<class_Type;
    std::cout << "\ndistance : " << distance;
    std::cout << "\nFare: " << calculateFare();
    std::cout << "\n";
}
// end display

// function book train
void Train::bookTrain()
{
    int seats, class_T, exitFlag = 1, actionForClassType, fare;
    std::cout << "\nEnter Destination:";
    std::cin >> toPlace;

    for (int i = 0; i < 5; i++)
    {
        if (toPlace == destination[i])
        {
            std::cout << destination[i];
            distance = dist[i];
        }
    }

    std::cout << "\nEnter number of seats to book:";
    std::cin >> seats;
    availableASeats = availableASeats - seats;

    while (exitFlag)
    {
        std::cout << "\n1.AC2TIER \n2.AC3TIER \n3.AC3ECONOMY\n4.FIRST  \n5.SLEEPER ";
        std::cout << "\nEnter Classtype For Booking The Seat: ";
        std::cin >> actionForClassType;

        switch (actionForClassType)
        {
        case 1:
            class_Type = TravelClass::AC2TIER;
            exitFlag = 0;
            break;

        case 2:
            class_Type = TravelClass::AC3TIER;
            exitFlag = 0;
            break;

        case 3:
            class_Type = TravelClass::AC3ECONOMY;
            exitFlag = 0;
            break;
        case 4:
            class_Type = TravelClass::FIRST;
            exitFlag = 0;
            break;
        case 5:
            class_Type = TravelClass::SLEEPER;
            exitFlag = 0;
            break;

        default: // error message if action is wrong
            std::cout << "\nUnable to Fetch Information. Please choose from above";
        }
    }
}
// end booktrain

// function to search train by trainNumber
int searchTrain(Train T[], std::string &dest)
{
    for (int s = 0; s < 5; s++)
    {
        if (T[s].getToPlace() == dest)
        {
            // return index of t if train is found
            return s;
        }
    }
    // return -1 if train is not found
    return -1;
}
// end searchTrain

// function to calculate fare
int Train::calculateFare()
{
    if (distance > 100 && distance < 500)
    {
        return 800;
    }
    else if (distance >= 500 && distance < 1000)
    {
        return 900;
    }
    else if (distance >= 1000 && distance < 1500)
    {
        return 1100;
    }
    else if (distance > 1500 && distance < 3000)
    {
        return 1300;
    }
    else
    {
        return 2000;
    }
}
// end calculate fare

// function to show Menu
void showMenu(Train T[], int size)
{
    int exitFlag = 1, action, k, i = 0, fare;
    std::string dest;

    while (exitFlag)
    {
        std::cout << "\n1.Book Train \n2.Search Train \n3.Display \n4.Calculate Fare \n5.Exit";
        std::cout << "\nChoose Action:";
        std::cin >> action;
        switch (action)
        {
        case 1: // Book Train
            if (i >= size)
            {
                std::cout << "\nnot able to book train already" << i << " trains booked";
            }
            else
            {
                T[i].bookTrain();
                i++;
            }
            break;

        case 2: // search train

            std::cout << "Enter Destination:";
            std::cin >> dest;

            k = searchTrain(T, dest);
            if (k == -1)
            {
                std::cout << "\ntrain not found";
            }
            else
            {
                T[k].display();
            }

            break;

        case 3: // display
            for (int j = 0; j < i; j++)
            {
                T[j].display();
            }
            break;

        case 4: // calculate the fare for Destination
            std::cout << "Enter destination:";
            std::cin >> dest;
            k = searchTrain(T, dest);
            fare = T[k].calculateFare();
            std::cout << "\nFare :" << fare;
            break;

        case 5: // exit
            exitFlag = 0;
            break;

        default: // error message if action is wrong
            std::cout << "\nInvalid Action. Please choose from above";
        }
    }
}
// end showMenu