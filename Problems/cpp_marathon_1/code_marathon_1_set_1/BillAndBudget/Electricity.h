#ifndef ELECTRICITY_H
#define ELECTRICITY_H

#include "ElectricitySlabs.h"
#include "WaterSlabs.h"

class Electricity
{
private:
    int sanctionLoad; // can be 1,3,5
    long presentReading, previousReading;

public:
    Electricity();
    Electricity(int load, long presentR, long previousR);
    ~Electricity();
    int calculateElectricityBill();

    void accept();
    void display();
};

#endif // ELECTRICITY_H
