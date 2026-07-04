#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include "DeviceType.h"

class Device
{
private:
    std::string _id;
    std::string _name;
    float _price;
    float _sar_value{1.0f}; // default value is 1.0f
    DeviceType _type;

public:
    // disable default constrctor
    Device() = delete;

    // disable copy construct
    Device(const Device &) = delete;

    // disable op copy constructor
    Device &operator=(Device &) = delete;

    // disable move construct
    Device(Device &&) = delete;

    // disable op move constructor
    Device &operator=(Device &&) = delete;

    // Parameterized constructor
    Device(std::string id, std::string name, float price, float sar_value, DeviceType type);

    // destrctor
    ~Device() = default;

    std::string id() const { return _id; }

    std::string name() const { return _name; }

    float price() const { return _price; }

    float sarValue() const { return _sar_value; }

    DeviceType type() const { return _type; }

    friend std::ostream &operator<<(std::ostream &os, const Device &rhs);
};

std::string DisplayDeviceType(DeviceType type);

#endif // DEVICE_H
