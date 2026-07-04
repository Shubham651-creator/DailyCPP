#ifndef CABRIDE_H
#define CABRIDE_H

#include <iostream>
#include "RidePaymentType.h"

class CabRide
{
private:
    std::string _ride_id;
    float _ride_fare;
    RidePaymentType _ride_payment_type;
    float _ride_distance;
    int _ride_passenger_count;
    std::string _ride_driver_name;
    float _ride_driver_rating;
    float _ride_gst_amount;

public:
    // disable default constructor
    CabRide() = delete;

    // disable copy constructor
    CabRide(const CabRide &) = delete;

    // disable copy assignment operator
    CabRide &operator=(CabRide &) = delete;

    // disable move constructor
    CabRide(CabRide &&) = delete;

    // disable move assignment operator
    CabRide &operator=(CabRide &&) = delete;

    // parameterized constructor
    CabRide(std::string id, float fare, RidePaymentType type,
            float distance,
            int passengerCount, std::string driverName,
            float rating, float gst);

    // destructor
    ~CabRide() = default;

    // getter of all attributes

    std::string rideId() const { return _ride_id; }

    float rideFare() const { return _ride_fare; }

    RidePaymentType ridePaymentType() const { return _ride_payment_type; }

    float rideDistance() const { return _ride_distance; }

    int ridePassengerCount() const { return _ride_passenger_count; }

    std::string rideDriverName() const { return _ride_driver_name; }

    float rideDriverRating() const { return _ride_driver_rating; }

    float rideGstAmount() const { return _ride_gst_amount; }

    friend std::ostream &operator<<(std::ostream &os, const CabRide &rhs);
};

std::string DisplayRidePaymentType(RidePaymentType type);

#endif // CABRIDE_H
