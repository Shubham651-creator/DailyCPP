

#ifndef CABBOOKING_H
#define CABBOOKING_H

#include <iostream>
#include <memory>
#include "PaymentModeType.h"

class CabBooking
{
private:
    std::string _booking_id;
    std::string _pickup_location;
    std::string _drop_location;
    float _base_fare;

public:
    // disable default constructor
    CabBooking() = default;

    // disable copy constructor
    CabBooking(const CabBooking &) = delete;

    // disable copy operator
    CabBooking &operator=(CabBooking &) = delete;

    // disable move constructor
    CabBooking(const CabBooking &&) = delete;

    // disable move operator
    CabBooking &operator=(CabBooking &&) = delete;

    // parameterized constructor
    CabBooking(std::string id, std::string pickup, std::string drop, float fare);

    // destructor
    virtual ~CabBooking() = default;

    friend std::ostream &operator<<(std::ostream &os, const CabBooking &rhs);

    // pure virtual function
    virtual float CabFareCalculation() = 0;

    std::string pickupLocation() const { return _pickup_location; }
    void setPickupLocation(const std::string &pickup_location) { _pickup_location = pickup_location; }

    std::string dropLocation() const { return _drop_location; }
    void setDropLocation(const std::string &drop_location) { _drop_location = drop_location; }

    float baseFare() const { return _base_fare; }
    void setBaseFare(float base_fare) { _base_fare = base_fare; }

    std::string bookingId() const { return _booking_id; }
    void setBookingId(const std::string &booking_id) { _booking_id = booking_id; }
};

#endif // CABBOOKING_H
