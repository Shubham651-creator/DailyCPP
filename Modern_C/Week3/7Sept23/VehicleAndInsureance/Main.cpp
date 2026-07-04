#include <iostream>
#include <functional>
#include <memory>
#include "Functionalities.h"
#include "Car.h"
#include "Vehicle.h"
#include "Insureance.h"
#include <thread>

using carPointer = std::unique_ptr<Car>;
using carContainer = std::list<carPointer>;
using rawContainerOfInsurance = std::list<Car *>;

using insurancePointer = std::unique_ptr<Insureance>;
using refPointer = std::reference_wrapper<insurancePointer>;

int main()
{
    insuranceContainer insuranceObjects;
    carContainer carObjects;
    std::optional<rawContainerOfInsurance> rawObject;

    // try
    // {
    //     CreateObjects(insuranceObjects, carObjects);
    //     for (carPointer &value : carObjects)
    //     {
    //         std::cout << *value << '\n';
    //     }

    //     std::cout << "------------------------------------------------------------\n";
    //     std::optional<rawContainerOfInsurance> rawInsurance =
    //         CarAboveInsuranceThreshold(carObjects, 20000000000);
    //     if (rawInsurance.has_value())
    //     {
    //         for (Car *value : rawInsurance.value())
    //         {
    //             std::cout << *value << '\n';
    //         }
    //     }
    //     else
    //     {
    //         std::cout << "\ngive function return empty Car Container.\n";
    //     }

    //     std::cout << "------------------------------------------------------------\n";
    //     std::cout << "A whether all car instances are matched with arg or not\n"
    //               << CheckCarType(carObjects, CarType::SUV) << "\n\n";

    //     std::cout << "------------------------------------------------------------\n";
    //     std::cout << "FindLowestHighestInterest(carObjects)\n";
    //     FindLowestHighestInterest(carObjects);

    //     std::cout << "------------------------------------------------------------\n";
    //     std::optional<rawContainerOfInsurance> rawCarObject = FunctionOfZeroDebt(carObjects, VehicleType::PRIVATE, "blue");
    //     if (rawCarObject.has_value())
    //     {
    //         for (Car *value : rawCarObject.value())
    //         {
    //             std::cout << *value << '\n';
    //         }
    //     }
    //     else
    //     {
    //         std::cout << "\ngive function return empty Car Container.\n";
    //     }

    //     std::cout << "------------------------------------------------------------\n measure the tax \n";
    //     std::optional<rawContainerOfInsurance> rawCarObject2 = MeasureTaxFunction(carObjects);
    //     if (rawCarObject2.has_value())
    //     {
    //         for (Car *value : rawCarObject2.value())
    //         {
    //             std::cout << *value << '\n';
    //         }
    //     }
    //     else
    //     {
    //         std::cout << "\ngive function return empty Car Container.\n";
    //     }

    //     std::cout << "------------------------------------------------------------\n";

    //     std::variant<int, std::string> ans = FunctionOfCarColour(carObjects, "red");

    //     std::visit([&](auto &&id)
    //                { std::cout << id << '\n'; },
    //                ans);
    //     std::cout << "------------------------------------------------------------\n";
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    try
    {
        // // to avoid std::decay, use std::ref()
        // std::thread t1(&CreateObjects, std::ref(insuranceObjects), std::ref(carObjects));
        // t1.join(); // main block

        // std::thread t2(&CarAboveInsuranceThreshold, std::ref(carObjects), 100);
        // t2.join();

        std::thread arr[2];

        arr[0] = std::thread(
            CreateObject,
            std::ref(insuranceObjects),
            std::ref(carObjects),
            "ins101",
            1000.0f,
            InsuranceType::ZERO_DEBT,
            "v101",
            2021,
            VehicleType::COMMERCIAL,
            CarType::HATCHBACK,
            2048300.0f,
            "Blue");

        arr[1] = std::thread(
            CreateObject,
            std::ref(insuranceObjects),
            std::ref(carObjects),
            "ins102",
            2000.0f,
            InsuranceType::REGULAR,
            "v102",
            2022,
            VehicleType::PRIVATE,
            CarType::SEDAN,
            4048300.0f,
            "Red");

        for (int i = 0; i < 2; i++)
        {
            arr[i].join();
        }

        // for (carPointer &value : carObjects)
        // {
        //     std::cout << *value << '\n';
        // }

        auto itr = carObjects.begin();

        std::cout << "\n\n"
                  << FindTotalPrice(*itr++, *itr++) << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}