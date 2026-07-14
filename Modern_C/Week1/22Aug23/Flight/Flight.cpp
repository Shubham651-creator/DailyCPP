#include "Flight.h"

Flight::Flight(int id, FlightType type, std::string start, std::string destination, float fare)
    : _id(id), _type(type), _startingLocation(start), _destinationLocation(destination), _fare(fare) {}

std::ostream &operator<<(std::ostream &os, const Flight &rhs)
{
    os << "_id: " << rhs._id
       << " _type: " << DiplayFlightType(rhs._type)
       << " _startingLocation: " << rhs._startingLocation
       << " _destinationLocation: " << rhs._destinationLocation
       << " _fare: " << rhs._fare;
    return os;
}

std::string DiplayFlightType(FlightType type)
{
    if (type == FlightType::COMMERCIAL)
        return "COMMERCIAL";
    if (type == FlightType::PRIVATE)
        return "PRIVATE";
    else
        return "SPECIAL";
}
