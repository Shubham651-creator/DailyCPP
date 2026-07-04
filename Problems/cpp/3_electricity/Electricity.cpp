#include <iostream>
#include "Electricity.h"

int load[3] = {1, 3, 5};
Electricity::Electricity()
{
    previousReading = 0;
    presentReading = 1;
    sactionLoad = 1;
    es = ElectricitySlabs ::E1;
}

Water ::Water()
{
    wPreviousReading = 0;
    wPresentReading = 10;
}

void Electricity::accept()
{
    std::cout << "\nEnter past Elecricity reading:";
    std::cin >> previousReading;
    std::cout << "\nEnter Present Elecricity reading:";
    std::cin >> presentReading;
    std::cout << "\nEnter Saction Load:";
    std::cin >> sactionLoad;
}

void Electricity::display()
{
    std::cout << "\npast Elecricity reading:" << previousReading;
    std::cout << "\nPresent Elecricity reading:" << presentReading;
    std::cout << "\nSaction Load:" << sactionLoad;
    std::cout << "\nElectricity Bill: " << calculateElectricityBill() << "\n\n";
}

float Electricity::calculateElectricityBill()
{
    float electricityBill;
    int consumption;
    consumption = presentReading - previousReading;
    if (presentReading < previousReading)
    {
        return 0.0f;
    }

    if (sactionLoad == 1)
    {
        es = ElectricitySlabs ::E1;
        electricityBill = (125 * sactionLoad) + ((consumption * 125) / 100);
    }
    else if (sactionLoad == 3)
    {
        electricityBill = (150 * sactionLoad) + ((consumption * 150) / 100);
    }
    else if (sactionLoad == 5)
    {
        electricityBill = (200 * sactionLoad) + ((consumption * 200) / 100);
    }
    return electricityBill;
}

float Water::calculateWaterBill()
{
    float amount, waterbill;
    long wconsumption = wPresentReading - wPreviousReading;
    if (wPresentReading < wPreviousReading)
    {
        return 0.0f;
    }
    if (wconsumption < 10000)
    {
        amount = 100 + wconsumption * 0.010;
    }
    else
    {
        amount = 150 + wconsumption * 0.015;
    }

    waterbill = (10 * 10) + ((amount * 15) / 1000);
    return waterbill;
}

void Water::accept()
{
    std::cout << "\nEnter past water reading about:";
    std::cin >> wPreviousReading;
    std::cout << "\nEnter Present water reading:";
    std::cin >> wPresentReading;
}

void Water::display()
{
    std::cout << "\npast water reading:" << wPreviousReading;
    std::cout << "\nPresent water reading detail:" << wPresentReading;
    std::cout << "\nwater Bill given: " << calculateWaterBill() << "\n\n";
}
