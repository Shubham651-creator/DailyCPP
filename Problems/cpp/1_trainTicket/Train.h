#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include "Travelclass.h"

class Train
{
    std::string trainName;
    int trainNumber;
    TravelClass class_Type;
    std::string fromplace = "New Delhi"; // const value
    std::string toPlace;
    int distance;

    static int availableASeats;

public:
    // default constructor
    Train();

    // function to display info
    void display();
    void bookTrain();
    int calculateFare();

    std::string getTrainName() const { return trainName; }
    void setTrainName(const std::string &trainName_) { trainName = trainName_; }

    int getTrainNumber() const { return trainNumber; }
    void setTrainNumber(int trainNumber_) { trainNumber = trainNumber_; }

    int getAvailableASeats() const { return availableASeats; }
    void setAvailableASeats(int availableASeats_) { availableASeats = availableASeats_; }

    TravelClass classType() const { return class_Type; }
    void setClassType(const TravelClass &classType) { class_Type = classType; }

    std::string getFromplace() const { return fromplace; }
    void setFromplace(const std::string &fromplace_) { fromplace = fromplace_; }

    std::string getToPlace() const { return toPlace; }
    void setToPlace(const std::string &toPlace_) { toPlace = toPlace_; }

    int getDistance() const { return distance; }
    void setDistance(int distance_) { distance = distance_; }
};

void search(Train, int);
void showMenu(Train *, int);

#endif // TRAIN_H