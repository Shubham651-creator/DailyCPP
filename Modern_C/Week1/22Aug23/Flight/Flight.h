#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include "FlightType.h"

class Flight
{
private:
    int _id;
    FlightType _type;
    std::string _startingLocation;
    std::string _destinationLocation;
    float _fare;

public:
    Flight() = delete;
    Flight(int id, FlightType type, std::string start, std::string destination, float fare);
    Flight(const Flight &object) = delete;
    Flight(Flight &&object) = delete;
    Flight &operator=(Flight &object) = delete;
    Flight &operator=(Flight &&object) = delete;
    ~Flight() = default;

    int id() const { return _id; }
    void setId(int id) { _id = id; }

    FlightType type() const { return _type; }
    void setType(const FlightType &type) { _type = type; }

    std::string startingLocation() const { return _startingLocation; }
    void setStartingLocation(const std::string &startingLocation) { _startingLocation = startingLocation; }

    std::string destinationLocation() const { return _destinationLocation; }
    void setDestinationLocation(const std::string &destinationLocation) { _destinationLocation = destinationLocation; }

    float fare() const { return _fare; }
    void setFare(float fare) { _fare = fare; }

    friend std::ostream &operator<<(std::ostream &os, const Flight &rhs);
};

std::string DiplayFlightType(FlightType type);

#endif // FLIGHT_H
