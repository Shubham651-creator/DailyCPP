#include <iostream>
#include "ElectricitySlab.h"

class Electricity
{
    int sactionLoad;
    long presentReading;
    long previousReading;
    enum ElectricitySlabs es;

public:
    void accept();
    Electricity();
    
    void display();
    int getSactionLoad() const { return sactionLoad; }
    void setSactionLoad(int sactionLoad_) { sactionLoad = sactionLoad_; }

    long getPresentReading() const { return presentReading; }
    void setPresentReading(long presentReading_) { presentReading = presentReading_; }

    long getPreviousReading() const { return previousReading; }
    void setPreviousReading(long previousReading_) { previousReading = previousReading_; }

    float calculateElectricityBill();

    int operator*(ElectricitySlabs Ele);
};

class Water
{
    long wPresentReading;
    long wPreviousReading;
    enum WaterSlabs ws;

public:
    Water();
    long wPregetWPresentReading() const { return wPresentReading; }
    void setWPresentReading(long wPrewPresentReading_) { wPresentReading = wPrewPresentReading_; }

    long wPregetWPreviousReading() const { return wPresentReading; }
    void setWPreviousReading(long wPrewPreviousReading_) { wPreviousReading = wPrewPreviousReading_; }

    float calculateWaterBill();
    void accept();
    void display();
};