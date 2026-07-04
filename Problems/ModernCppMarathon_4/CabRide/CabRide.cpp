#include "CabRide.h"
std::ostream &operator<<(std::ostream &os, const CabRide &rhs)
{
    os << "_ride_id: " << rhs._ride_id
       << " _ride_fare: " << rhs._ride_fare
       << " _ride_payment_type: " << DisplayRidePaymentType(rhs._ride_payment_type)
       << " _ride_distance: " << rhs._ride_distance
       << " _ride_passenger_count: " << rhs._ride_passenger_count
       << " _ride_driver_name: " << rhs._ride_driver_name
       << " _ride_driver_rating: " << rhs._ride_driver_rating
       << " _ride_gst_amount: " << rhs._ride_gst_amount;
    return os;
}

std::string DisplayRidePaymentType(RidePaymentType type)
{
    if (type == RidePaymentType::CARD)
    {
        return "CARD";
    }
    if (type == RidePaymentType::CASH)
    {
        return "CASH";
    }
    return "UPI";
}

CabRide::CabRide(std::string id, float fare, RidePaymentType type,
                 float distance,
                 int passengerCount, std::string driverName,
                 float rating, float gst)
    : _ride_id(id), _ride_fare(fare),
      _ride_payment_type(type),
      _ride_distance(distance),
      _ride_passenger_count(passengerCount),
      _ride_driver_name(driverName),
      _ride_driver_rating(rating),
      _ride_gst_amount(gst)
{
    if (passengerCount < 1 || passengerCount > 6)
    {
        throw std::runtime_error("Passenger count must be in 1 to 6\n");
    }
    if (rating < 1 || rating > 5)
    {
        throw std::runtime_error("rating must be in 1 to 5\n");
    }

    gst = 0.33f * fare;
}
