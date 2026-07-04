#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>

class Flight
{
private:
    int flightNumber;
    std::string flightDestination;
    float flightDistance;
    float flightFuel;

public:
    Flight();
    ~Flight();
    Flight(int fNumber, std::string fDestination, float fDistance);

    float calculateFuelQuantity(float fDistance);
    void feedInfo();
    void showInfo();

    int getFlightNumber() const { return flightNumber; }
    void setFlightNumber(int flightNumber_) { flightNumber = flightNumber_; }

    std::string getFlightDestination() const { return flightDestination; }
    void setFlightDestination(const std::string &flightDestination_) { flightDestination = flightDestination_; }

    float getFlightDistance() const { return flightDistance; }
    void setFlightDistance(float flightDistance_) { flightDistance = flightDistance_; }
};

#endif // FLIGHT_H
