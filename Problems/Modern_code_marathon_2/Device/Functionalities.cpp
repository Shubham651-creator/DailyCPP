#include "Functionalities.h"
#include <memory.h>

// list container which stores Device objects
using Container = std::list<std::shared_ptr<Device>>;

// functional pointer
using Pointer = std::function<void(Container &)>;

void CreateObjects(Container &data) noexcept
{
    data.push_back(std::make_shared<Device>("101", "TV", 300000.0f, 1.30f, DeviceType::WORKSTATION));
    data.push_back(std::make_shared<Device>("102", "Mobile", 12000.0f, 1.10f, DeviceType::MOBILE));
    data.push_back(std::make_shared<Device>("103", "Digital watch", 8000.0f, 1.0f, DeviceType::ACCESSORY));
    data.push_back(std::make_shared<Device>("104", "Washing Machine", 26000.0f, 1.50f, DeviceType::WORKSTATION));
    data.push_back(std::make_shared<Device>("105", "Laptop", 9800000.0f, 1.90f, DeviceType::ACCESSORY));
}

void ShowResults(Container &data, Pointer fn)
{
    // check container empty or not
    if (data.empty())
    {
        throw std::runtime_error("Containe is empty\n");
    }

    fn(data);
}

void FindDiscountPrice(Container &data)
{
    // check container empty or not
    if (data.empty())
    {
        throw std::runtime_error("Containe is empty\n");
    }

    float discountPrice{0.0f};
    for (auto &object : data)
    {
        if (DeviceType::MOBILE == object->type() || DeviceType::WORKSTATION == object->type())
        {
            discountPrice = object->price() * 0.1f;
            std::cout << "The Discout price of " << DisplayDeviceType(object->type()) << " is " << discountPrice
                      << '\n';
        }

        if (DeviceType::MOBILE == object->type())
        {
            discountPrice = object->price() * 0.2f;
            std::cout << "The Discout price of " << DisplayDeviceType(object->type()) << " is " << discountPrice
                      << '\n';
        }
    }
}

void FindTaxAmount(Container &data)
{
    // check container empty or not
    if (data.empty())
    {
        throw std::runtime_error("Containe is empty\n");
    }

    float taxAmount{0.0f};
    for (auto &object : data)
    {
        if (object->sarValue() >= 1.0f && object->sarValue() <= 1.5f)
        {
            taxAmount = object->price() * 0.18f;
            std::cout << "The tax Amount is " << object->sarValue() << " is "
                      << taxAmount << '\n';
        }

        if (object->sarValue() >= 1.5f && object->sarValue() <= 2.0f)
        {
            taxAmount = object->price() * 0.28f;
            std::cout << "The tax Amount is " << object->sarValue() << " is "
                      << taxAmount << '\n';
        }
    }
}
