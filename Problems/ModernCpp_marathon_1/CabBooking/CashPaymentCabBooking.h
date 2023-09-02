 

#ifndef CASHPAYMENTCABBOOKING_H
#define CASHPAYMENTCABBOOKING_H

#include <iostream>
#include <list>
#include "OnlinePaymentCabBooking.h"
#include "PaymentModeType.h"
#include "CabBooking.h"

// list container which holds objects of onlinePayment
// and cashPayment
using container = std::list<std::shared_ptr<CabBooking>>;

// cashPayment is inherited from CabBooking
class CashPaymentCabBooking : public CabBooking
{
private:
    int _reward_points_claimed;

public:
    // disable default constructor
    CashPaymentCabBooking() = delete;

    // disable copy constructor
    CashPaymentCabBooking(const CashPaymentCabBooking &) = delete;

    // disable copy operator constructor
    CashPaymentCabBooking &operator=(CashPaymentCabBooking &) = delete;

    // disable copy constructor
    CashPaymentCabBooking(const CashPaymentCabBooking &&) = delete;

    // disable copy operator constructor
    CashPaymentCabBooking &operator=(CashPaymentCabBooking &&) = delete;

    // parameterized constructor
    CashPaymentCabBooking(std::string id, std::string pickup, std::string drop, float fare, int reward);

    // destructor
    ~CashPaymentCabBooking() = default;

    // overriden member function
    float CabFareCalculation() override;

    int rewardPointsClaimed() const { return _reward_points_claimed; }
    void setRewardPointsClaimed(int reward_points_claimed) { _reward_points_claimed = reward_points_claimed; }

    friend std::ostream &operator<<(std::ostream &os, const CashPaymentCabBooking &rhs);
};

 

#endif // CASHPAYMENTCABBOOKING_H
