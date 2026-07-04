#ifndef TOURISTVEHICLE_H
#define TOURISTVEHICLE_H

#include <iostream>
#include <list>
#include <memory>
#include "TouristVehicleType.h"
#include "Permit.h"

// reference wrapper around shared ptr of Permit class
using PermitPointer = std::reference_wrapper<std::shared_ptr<Permit>>;

class TouristVehicle
{
private:
    std::string _number;
    TouristVehicleType _type;
    int _seat_count;
    float _per_hour_booking_charge;
    PermitPointer _permit;

public:
    // disable default constructor
    TouristVehicle() = delete;

    // disable copy constructor
    explicit TouristVehicle(const TouristVehicle &) = delete;

    // disable copy operator constructor
    TouristVehicle &operator=(TouristVehicle &) = delete;

    // disable move constructor
    TouristVehicle(const TouristVehicle &&) = delete;

    // disable move operator constructor
    TouristVehicle &operator=(TouristVehicle &&) = delete;

    // paramterized constructor
    TouristVehicle(std::string number, TouristVehicleType type, int seat, float charge, PermitPointer permit);

    // destructor
    ~TouristVehicle() = default;

    std::string number() const { return _number; }
    void setNumber(const std::string &number) { _number = number; }

    TouristVehicleType type() const { return _type; }
    void setType(const TouristVehicleType &type) { _type = type; }

    int seatCount() const { return _seat_count; }
    void setSeatCount(int seat_count) { _seat_count = seat_count; }

    float perHourBookingCharge() const { return _per_hour_booking_charge; }
    void setPerHourBookingCharge(float per_hour_booking_charge) { _per_hour_booking_charge = per_hour_booking_charge; }

    PermitPointer permit() const { return _permit; }

    friend std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs);
};

std::string DisplayTouristVehicleType(TouristVehicleType touristType);

#endif // TOURISTVEHICLE_H
