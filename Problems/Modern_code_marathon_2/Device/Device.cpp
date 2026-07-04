#include "Device.h"

std::ostream &operator<<(std::ostream &os, const Device &rhs)
{
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _price: " << rhs._price;

    if (rhs._sar_value >= 1.0f && rhs._sar_value <= 2.0f)
    {
        os << " _sar_value: " << rhs.sarValue();
    }
    else
    {
        std::cout << "Radiation level must be above 1.0f and below 2.0f\n";
    }
    os << " _type: " << DisplayDeviceType(rhs._type);
    return os;
}

std::string DisplayDeviceType(DeviceType type)
{
    if (type == DeviceType::ACCESSORY)
        return "ACCESSORY";
    if (type == DeviceType::MOBILE)
        return "MOBILE";

    return "WORKSTATION";
}

Device::Device(std::string id, std::string name, float price, float sar_value, DeviceType type)
    : _id(id), _name(name), _price(price), _sar_value(sar_value), _type(type) {}
