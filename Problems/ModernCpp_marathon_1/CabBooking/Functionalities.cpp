#include "Functionalities.h"

void CreateObjects(container &objects)
{

    // three objects of onlinePayment
    std::shared_ptr<OnlinePaymentCabBooking> online1 = std::make_shared<OnlinePaymentCabBooking>(
        "101",
        "Pune",
        "Delhi",
        200.0f,
        PaymentModeType::CARD,
        4);

    std::shared_ptr<OnlinePaymentCabBooking> online2 = std::make_shared<OnlinePaymentCabBooking>(
        "102",
        "Bhor",
        "Delhi",
        600.0f,
        PaymentModeType::UPI,
        4);

    std::shared_ptr<OnlinePaymentCabBooking> online3 = std::make_shared<OnlinePaymentCabBooking>(
        "103",
        "Pune",
        "Dehradun",
        1200.0f,
        PaymentModeType::ONLINE,
        4);

    // three objects of CashPayment
    std::shared_ptr<CashPaymentCabBooking> cash1 = std::make_shared<CashPaymentCabBooking>(
        "201",
        "Washignton",
        "bhihar",
        3000.0f,
        111);

    std::shared_ptr<CashPaymentCabBooking> cash2 = std::make_shared<CashPaymentCabBooking>(
        "202",
        "Washim",
        "bhihar",
        430.0f,
        41);

    std::shared_ptr<CashPaymentCabBooking> cash3 = std::make_shared<CashPaymentCabBooking>(
        "203",
        "Washignton",
        "bhor",
        4600.0f,
        291);

    // push into container
    objects.emplace_back(online1);
    objects.emplace_back(online2);
    objects.emplace_back(online3);
    objects.emplace_back(cash1);
    objects.emplace_back(cash3);
    objects.emplace_back(cash2);
}

container ConditionPickupLocation(container &objects, std::string location)
{
    if (objects.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    container store;
    for (std::shared_ptr<CabBooking> &value : objects)
    {
        if (location == value->pickupLocation())
        {
            store.push_back(value);
        }
    }

    return store;
}

std::string MaxCabFareCalculation(container &objects)
{
    float max = 0;
    std::string id = "102";
    if (objects.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    for (std::shared_ptr<CabBooking> &value : objects)
    {
        if (max < value->CabFareCalculation())
        {
            max = value->CabFareCalculation();
            id = value->bookingId();
        }
    }
    return id;
}

container FirstNInstance(container &objects, int N)
{
    if (objects.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    container store;
    int count = 0;
    for (std::shared_ptr<CabBooking> &value : objects)
    {
        if (count <= N)
        {
            store.push_back(value);
            count++;
        }
        else
        {
            break;
        }
    }

    return store;
}

float AverageOfOnlinePayment(container &objects)
{
    if (objects.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    float sum = 0;
    float count = 0;
    for (std::shared_ptr<CabBooking> &value : objects)
    {
        sum += value->baseFare();
        count++;
    }

    return sum / count;
}
