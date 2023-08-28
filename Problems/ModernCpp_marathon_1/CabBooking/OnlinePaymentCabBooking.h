 

#ifndef ONLINEPAYMENTCABBOOKING_H
#define ONLINEPAYMENTCABBOOKING_H

#include <iostream>
#include <list>
#include "CabBooking.h"
#include "PaymentModeType.h"

// list container which holds objects of onlinePayment
// and cashPayment
using container = std::list<std::shared_ptr<CabBooking>>;

// OnlinePayment is inherited from CabBooking
class OnlinePaymentCabBooking : public CabBooking
{
private:
    PaymentModeType _payment_mode;
    int _drop_stops_count;

public:
    // disable default constructor
    OnlinePaymentCabBooking() = default;

    // disable copy constructor
    OnlinePaymentCabBooking(const OnlinePaymentCabBooking &) = delete;

    // disable copy operator constructor
    OnlinePaymentCabBooking &operator=(OnlinePaymentCabBooking &) = delete;

    // disable move constructor
    OnlinePaymentCabBooking(const OnlinePaymentCabBooking &&) = delete;

    // disable move operator constructor
    OnlinePaymentCabBooking &operator=(OnlinePaymentCabBooking &&) = delete;

    // parameterized constructor
    OnlinePaymentCabBooking(std::string id, std::string pickup, std::string drop, float fare, PaymentModeType mode, int dropCount);

    // destructor
    ~OnlinePaymentCabBooking() = default;

    friend std::ostream &operator<<(std::ostream &os, const OnlinePaymentCabBooking &rhs);

    // overriden member function
    float CabFareCalculation( );

    PaymentModeType paymentMode() const { return _payment_mode; }
    void setPaymentMode(const PaymentModeType &payment_mode) { _payment_mode = payment_mode; }

    int dropStopsCount() const { return _drop_stops_count; }
    void setDropStopsCount(int drop_stops_count) { _drop_stops_count = drop_stops_count; }
};

std::string DisplayPaymentMode(PaymentModeType type);


#endif // ONLINEPAYMENTCABBOOKING_H
