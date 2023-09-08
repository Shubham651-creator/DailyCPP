#include <iostream>
#include <list>
#include <memory.h>
#include <functional>
#include <algorithm>
#include "Device.h"
#include "Functionalities.h"

// list container which stores Device objects
using Container = std::list<std::shared_ptr<Device>>;

// functional pointer
using Pointer = std::function<void(Container &)>;

// functional pointer for lambda's functions
using devicePointer = std::function<void(Device &)>;

int main()
{

    Container objects;

    try
    {
        CreateObjects(objects);

        for (auto &value : objects)
        {
            std::cout << *value << "\n";
        }

        Pointer discountPtr = &FindDiscountPrice;
        ShowResults(objects, discountPtr);

        Pointer taxPointer = &FindTaxAmount;
        ShowResults(objects, taxPointer);

        // lambda functions
        devicePointer f1 = [](Device &device)
        {
            std::cout << "Sar Value is " << device.sarValue() << '\n';
            std::cout << "Price is " << device.price() << "\n";
        };
        for(auto& value : objects){
            f1(*value);
        }

        devicePointer f2 = [](Device &device)
        {
            if(device.type() == DeviceType::MOBILE){
                std::cout<<"The id is "<< device.id()<<'\n';
            }

            if(device.type() == DeviceType::WORKSTATION){
                std::cout<<"The id is "<< device.name()<<'\n';
            }

            if(device.type() == DeviceType::ACCESSORY){
                std::cout<<"The id is "<< device.sarValue()<<'\n';
            }
        };
        for(auto& value : objects){
            f2(*value);
        }


    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}