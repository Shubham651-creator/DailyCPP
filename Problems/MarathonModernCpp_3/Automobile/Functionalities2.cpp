#include "Functionalities2.h"
#include <mutex>

std::mutex mt;

using pointerOfEngine = std::shared_ptr<Engine>;
using pointerOfAutomobile = std::shared_ptr<Automobile>;

using EngineContainer = std::vector<pointerOfEngine>;
using AutomobileContainer = std::vector<pointerOfAutomobile>;

void CreateObjectEngine(EngineContainer &engineObjects, float size, int hPower, EngineType etype)
{
    engineObjects.emplace_back(std::make_shared<Engine>(size, hPower, etype));
}

void CreateObjectsAutomobile(AutomobileContainer &automobileObjects, EngineContainer &engineObjects,
                             std::variant<int, std::string> id, AutomobileType autoType, std::string brand, pointerOfEngine engine,
                             float price, std::array<int, 4> pressure)
{

    mt.lock();

    automobileObjects.push_back(std::make_shared<Automobile>(
        id, autoType, brand, std::ref(engine), price, pressure));

    mt.unlock();
}

std::optional<AutomobileContainer> HorsePowerAboveThreshold(AutomobileContainer &automobileObjects, int threshold)
{
    if (automobileObjects.empty())
    {
        throw std::runtime_error("Conatiner is empty\n");
    }

    AutomobileContainer store;

    for (auto &value : automobileObjects)
    {
        if (value.get()->engine().get()->horsepower() > threshold)
        {
            store.push_back(value);
        }
    }

    if (store.empty())
    {
        std::cout << "output container is empty\n";
    }

    return std::make_optional(store);
}

std::vector<float> CalculateTax(AutomobileContainer &automobileObjects)
{
    if (automobileObjects.empty())
    {
        throw std::runtime_error("Conatiner is empty\n");
    }

    std::vector<float> store;

    for (auto &value : automobileObjects)
    {
        if (value.get()->engine().get()->type() == EngineType::DIESEL)
        {
            float tax = value.get()->engine().get()->horsepower() * value.get()->price();
            store.push_back(tax);
        }
        if (value.get()->engine().get()->type() == EngineType::PETROL)
        {
            float tax = value.get()->engine().get()->horsepower() * value.get()->price() * value.get()->engine().get()->engineSize();
            store.push_back(tax);
        }
    }
    return store;
}

int HorspowerPriceAboveThreshold(AutomobileContainer &automobileObjects,
                                 int thresholdHorse, float threholdPrice)
{
    if (automobileObjects.empty())
    {
        throw std::runtime_error("Conatiner is empty\n");
    }

    int count = 0;

    for (auto &value : automobileObjects)
    {
        if (thresholdHorse < value.get()->engine().get()->horsepower() &&
            threholdPrice < value.get()->price())
        {
            count++;
        }
    }

    return count;
}

void MinimumPrice(AutomobileContainer &automobileObjects)
{
    if (automobileObjects.empty())
    {
        throw std::runtime_error("Conatiner is empty\n");
    }

    auto itr = std::min_element(
        automobileObjects.begin(),
        automobileObjects.end(),
        [&](pointerOfAutomobile &obj1, pointerOfAutomobile &obj2)
        {
            return obj1.get()->price() < obj2.get()->price();
        });

    std::cout << *itr.base()->get()->engine() << '\n';
}
