#include "CashPaymentCabBooking.h"
#include "OnlinePaymentCabBooking.h"

CashPaymentCabBooking::CashPaymentCabBooking(std::string id, std::string pickup, std::string drop, float fare, int reward)
    : CabBooking(id, pickup, drop, fare), _reward_points_claimed(reward) {}

float CashPaymentCabBooking::CabFareCalculation()
{
    container objects;
    float fare = 0.0f;
    for (std::shared_ptr<CabBooking> object : objects)
    {
        if (_reward_points_claimed < 0.25 * object->baseFare())
        {
            return 2 * baseFare();
        }
        else
        {
            return 1.5 * baseFare();
        }
    }

    return fare;
}

std::ostream &operator<<(std::ostream &os, const CashPaymentCabBooking &rhs)
{
    os << static_cast<const CabBooking &>(rhs)
       << " _reward_points_claimed: " << rhs._reward_points_claimed;
    return os;
}
