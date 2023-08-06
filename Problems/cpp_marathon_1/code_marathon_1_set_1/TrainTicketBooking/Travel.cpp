#include <iostream>
#include "Travel.h"

Travel::Travel()
{
    trainName = "Udaan#123";
    trainNumber = 123;
    availableSeats = 420;
    travelClass = TravelClass::AC2TIER;
    fromPlace = "New Delhi";
    toPlace = "Surat";
    distance = 2000;
}

Travel::Travel(std::string name, int number, int availSeats, enum TravelClass travelClass, std::string toplace, int dist)
    : trainName(name), trainNumber(number), availableSeats(availSeats), travelClass(travelClass), toPlace(toplace), distance(dist)
{
}

Travel::~Travel()
{
}

void Travel::accept()
{
    int chooseEnum;
    std::cin >> trainName >> trainNumber >> availableSeats >> toPlace >> chooseEnum;
    travelClass = returnEnum(chooseEnum);
}

void Travel::display()
{
    std::cout << "TrainName :" << trainName
              << "\nTrainNumber:" << trainNumber
              << "\navailable seats: " << availableSeats
              << "\n from place:" << fromPlace << "\nTo place:"
              << toPlace << "\nTrain Class: "<<displayEnum()<<"\n";
    
    distance = calculateDistance(toPlace);
    std::cout << "The total fare will be " << calculateFare(distance) << "\n\n";
}

int Travel::calculateDistance(std::string toplace)
{
   if(toplace == "kolphapur") return 1720;
   if(toplace =="surat") return 1205;
   if(toplace == "nagpur") return 980;
   if(toplace == "ranchi") return 2100;
   if(toplace == " dehardun") return 300;

   return 500;
}

int Travel::calculateFare(int distance)
{
    if (distance > 100 && distance < 500)
        return 800;
    if (distance >= 500 && distance < 1000)
        return 900;
    if (distance >= 1000 && distance < 1500)
        return 1100;
    if (distance >= 1500 && distance <= 2000)
        return 1300;
    else
        return 2000;
}

TravelClass Travel::returnEnum(int chooseEnum)
{
    if(chooseEnum == 1) return TravelClass::AC2TIER;
    if(chooseEnum == 2) return TravelClass::FIRST;
    if( chooseEnum == 3) return TravelClass::SLEEPER;
    if(chooseEnum == 4) return TravelClass::AC3TIER;
    else return TravelClass::AC3ECONOMY;
}

std::string Travel::displayEnum( ){
    int check = (int)travelClass;
    switch (check)
    {
    case 0:return "AC2TIER";
    case 1: return "FIRST";
    case 2: return "SLEEPER";
    case 3: return "AC3TIER";
    case 4: return "AC3ECONOMY";
    }

    return "nOTHING";   
}