#ifndef TRAVEL_H
#define TRAVEL_H

#include <iostream>
#include "TravelClass.h"

class Travel
{
private:
    std::string trainName;
    int trainNumber;
    int availableSeats;
    enum TravelClass travelClass;
    std::string fromPlace;
    std::string toPlace;
    int distance;

public:
    Travel();
    Travel(std::string name, int number, int availSeats, enum TravelClass travelClass, std::string toplace, int dist);
    ~Travel();

    void accept();
    void display();
    int calculateDistance(std::string toplace);
    int calculateFare(int distance);
    std::string displayEnum();
    TravelClass returnEnum(int);

    std::string getTrainName() const { return trainName; }
    void setTrainName(const std::string &trainName_) { trainName = trainName_; }

    int getTrainNumber() const { return trainNumber; }
    void setTrainNumber(int trainNumber_) { trainNumber = trainNumber_; }

    int getAvailableSeats() const { return availableSeats; }
    void setAvailableSeats(int availableSeats_) { availableSeats = availableSeats_; }

    enum TravelClass getTravelClass() const { return travelClass; }
    void setTravelClass(const enum TravelClass &travelClass_) { travelClass = travelClass_; }

    std::string getFromPlace() const { return fromPlace; }
    void setFromPlace(const std::string &fromPlace_) { fromPlace = fromPlace_; }

    std::string getToPlace() const { return toPlace; }
    void setToPlace(const std::string &toPlace_) { toPlace = toPlace_; }

    int getDistance() const { return distance; }
    void setDistance(int distance_) { distance = distance_; }
};

#endif // TRAVEL_H
