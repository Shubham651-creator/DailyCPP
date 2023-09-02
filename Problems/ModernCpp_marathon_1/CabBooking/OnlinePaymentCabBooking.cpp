#include "OnlinePaymentCabBooking.h"
#include "PaymentModeType.h"

std::ostream &operator<<(std::ostream &os, const OnlinePaymentCabBooking &rhs)
{
    os << static_cast<const CabBooking &>(rhs);

    os << "\n _payment_mode: " << DisplayPaymentMode(rhs._payment_mode)
       << "\n _drop_stops_count: " << rhs._drop_stops_count;
    return os;
}

std::string DisplayPaymentMode(PaymentModeType type)
{
    if (type == PaymentModeType::CARD)
        return "CARD";
    if (type == PaymentModeType::ONLINE)
        return "ONLINE";
    if (type == PaymentModeType::WALLET)
        return "WALLET";
    return "UPI";
}

OnlinePaymentCabBooking::OnlinePaymentCabBooking(std::string id, std::string pickup, std::string drop, float fare, PaymentModeType mode, int dropCount)
    : CabBooking(id, pickup, drop, fare), _payment_mode(mode), _drop_stops_count(dropCount) {}

float OnlinePaymentCabBooking::CabFareCalculation()
{

    float fare = 0.0f;

    if (_payment_mode == PaymentModeType::UPI)
    {
        fare = baseFare() + _drop_stops_count * 0.1;
    }

    if (_payment_mode == PaymentModeType::CARD || _payment_mode == PaymentModeType::UPI)
    {
        fare = baseFare() * _drop_stops_count;
    }

    return fare;
}
