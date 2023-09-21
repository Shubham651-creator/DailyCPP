#include "Functionalities.h"

using pointerOfcharging = std::shared_ptr<ChargingUnit>;

// container containes objects of ChargingUnit
using containerOfCharging = std::vector<pointerOfcharging>;

void CreateObjects(containerOfCharging &chargingObject)
{
    chargingObject.push_back(std::make_shared<ChargingUnit>(
        "unit101",
        100.0f,
        std::vector{1.0f, 2.0f, 3.0f, 4.0f, 5.0f},
        1200.0f,
        1300.0f));
    chargingObject.push_back(std::make_shared<ChargingUnit>(
        "unit102",
        200.0f,
        std::vector{2.0f, 2.0f, 3.0f, 4.0f, 5.0f},
        2200.0f,
        2300.0f));
    chargingObject.push_back(std::make_shared<ChargingUnit>(
        "unit103",
        300.0f,
        std::vector{3.0f, 2.0f, 3.0f, 4.0f, 5.0f},
        3200.0f,
        3300.0f));
    chargingObject.push_back(std::make_shared<ChargingUnit>(
        "unit104",
        400.0f,
        std::vector{4.0f, 2.0f, 3.0f, 4.0f, 5.0f},
        4200.0f,
        4300.0f));
    chargingObject.push_back(std::make_shared<ChargingUnit>(
        "unit105",
        500.0f,
        std::vector{5.0f, 2.0f, 3.0f, 4.0f, 5.0f},
        5200.0f,
        5300.0f));

    // Every object must have unique id and capacity value
    for (int i = 0; i < 4; i++)
    {
        if (chargingObject[i].get()->id() == chargingObject[i + 1].get()->id())
        {
            throw std::runtime_error("Not unique id\n");
        }
        if (chargingObject[i].get()->capacity() == chargingObject[i + 1].get()->capacity())
        {
            throw std::runtime_error("Not unique capacity\n");
        }
    }
}

float GSTAmountFunction(containerOfCharging &chargingObject)
{
    // check empty
    if (chargingObject.empty())
    {
        throw std::runtime_error("Contaier is empty\n");
    }

    for (auto &value : chargingObject)
    {
        float total = 0;
        std::visit([&](auto &&sum)
                   {
                   
                    for(auto& i : sum){
                        total = total + i ;
                    } },
                   value.get()->last5DischargedUnits());

        if (total > 100)
        {
            return total * 0.18f;
        }
        else
        {
            return total * 0.10f;
        }
    }

    return 0.0f;
}

containerOfCharging HightAndSecondHighest(containerOfCharging &chargingObject)
{
    // check empty
    if (chargingObject.empty())
    {
        throw std::runtime_error("Contaier is empty\n");
    }

    containerOfCharging instance;

    std::sort(
        chargingObject.begin(),
        chargingObject.end(),
        [](pointerOfcharging &obj1, pointerOfcharging &obj2)
        {
            return obj1.get()->capacity() > obj2.get()->capacity();
        });

    instance.push_back(chargingObject[0]);
    instance.push_back(chargingObject[1]);

    return instance;
}

bool RatingKWAbove3(containerOfCharging &chargingObject)
{
    // check empty
    if (chargingObject.empty())
    {
        throw std::runtime_error("Contaier is empty\n");
    }
    return std::all_of(
        chargingObject.begin(),
        chargingObject.end(),
        [&](pointerOfcharging &obj1)
        {
            return obj1.get()->costPerKw() > 3;
        });
}
std::optional<containerOfCharging> CheckId(containerOfCharging &chargingObject, std::string id)
{
    // check empty
    if (chargingObject.empty())
    {
        throw std::runtime_error("Contaier is empty\n");
    }

    containerOfCharging store;
    for (auto value : chargingObject)
    {
        if (value.get()->id() == id)
        {
            store.push_back(value);
        }
    }
    return store;
}

float AverageOfCostPerKW(containerOfCharging &chargingObject)
{
    float sum = 0;
    for (auto &value : chargingObject)
    {
        if (value.get()->costPerKw() > 2.5)
        {
            sum += value.get()->ratingKw();
        }
    }
    return sum / chargingObject.size();
}
