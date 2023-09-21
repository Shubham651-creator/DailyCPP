#include <iostream>
#include <memory>
#include <algorithm>
#include <numeric>
#include <variant>
#include <thread>
#include <future>
#include "Automobile.h"
#include "Engine.h"
#include "Functionalities2.h"

using pointerOfEngine = std::shared_ptr<Engine>;
using pointerOfAutomobile = std::shared_ptr<Automobile>;

using EngineContainer = std::vector<pointerOfEngine>;
using AutomobileContainer = std::vector<pointerOfAutomobile>;

int main()
{

    AutomobileContainer autoObjects;
    EngineContainer engineObjects;

    try
    {
        CreateObjectEngine(std::ref(engineObjects), 2.0f, 400, EngineType::DIESEL);
        CreateObjectEngine(std::ref(engineObjects), 3.0f, 300, EngineType::PETROL);
        CreateObjectEngine(std::ref(engineObjects), 4.0f, 400, EngineType::DIESEL);
        CreateObjectEngine(std::ref(engineObjects), 4.1f, 500, EngineType::PETROL);
        CreateObjectEngine(std::ref(engineObjects), 1.40f, 560, EngineType::DIESEL);

        std::array<std::thread, 5> threadObjects;

        threadObjects[0] = std::thread(CreateObjectsAutomobile, std::ref(autoObjects), std::ref(engineObjects),
                                       101, AutomobileType::COMMUTE,
                                       "Dhoom", std::ref(engineObjects[0]), 20000.0f, std::array{1, 2, 3, 4});

        threadObjects[1] = std::thread(CreateObjectsAutomobile, std::ref(autoObjects), std::ref(engineObjects),
                                       102, AutomobileType::COMMUTE,
                                       "Dhoom", std::ref(engineObjects[1]), 20000.0f, std::array{1, 2, 3, 4});
        threadObjects[2] = std::thread(CreateObjectsAutomobile, std::ref(autoObjects), std::ref(engineObjects),
                                       103, AutomobileType::COMMUTE,
                                       "Dhoom", std::ref(engineObjects[2]), 20000.0f, std::array{1, 2, 3, 4});
        threadObjects[3] = std::thread(CreateObjectsAutomobile, std::ref(autoObjects), std::ref(engineObjects),
                                       104, AutomobileType::COMMUTE,
                                       "Dhoom", std::ref(engineObjects[3]), 20000.0f, std::array{1, 2, 3, 4});
        threadObjects[4] = std::thread(CreateObjectsAutomobile, std::ref(autoObjects), std::ref(engineObjects),
                                       105, AutomobileType::COMMUTE,
                                       "Dhoom", std::ref(engineObjects[4]), 20000.0f, std::array{1, 2, 3, 4});

        for (auto &value : threadObjects)
        {

            value.join();
        }

        for (auto &value : autoObjects)
        {
            std::cout << *value << '\n';
        }

        std::cout << "Second functional\n";
        if (HorsePowerAboveThreshold(autoObjects, 30000).has_value())
        {
            for (auto &value : HorsePowerAboveThreshold(autoObjects, 30000).value())
            {
                std::cout << *value << '\n';
            }
        }
        else
        {
            std::cout << "nothing\n";
        }

        std::cout << "Third functioanl\n";
        for (auto &value : CalculateTax(autoObjects))
        {
            std::cout << value << '\t';
        }

        std::cout << "\nforuth function\n"
                  << HorspowerPriceAboveThreshold(autoObjects, 200, 2000.0f) << '\n';

        std::cout << "fifth function\n";

        auto count = std::bind(&HorspowerPriceAboveThreshold, std::ref(autoObjects), 320, 700000.0f);

        std::cout << "sixth function\n";
        MinimumPrice(autoObjects);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}