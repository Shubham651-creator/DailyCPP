#include "Functionalities.h"
#include <memory>
#include <functional>
#include <list>

using refPointer = std::reference_wrapper<std::shared_ptr<Sensor>>;
// store the shared ptr in container of list
using container = std::list<refPointer>;

// create 5 objects
std::shared_ptr<Sensor> s1 = std::make_shared<Sensor>(
    101,
    "sensor1",
    SensorType::CABIN_PRESSURE,
    100);
std::shared_ptr<Sensor> s2 = std::make_shared<Sensor>(
    102,
    "sensor2",
    SensorType::TEMPERATURE,
    200);
std::shared_ptr<Sensor> s3 = std::make_shared<Sensor>(
    103,
    "sensor3",
    SensorType::CABIN_PRESSURE,
    300);
std::shared_ptr<Sensor> s4 = std::make_shared<Sensor>(
    104,
    "sensor4",
    SensorType::TEMPERATURE,
    400);
std::shared_ptr<Sensor> s5 = std::make_shared<Sensor>(
    105,
    "sensor5",
    SensorType::TYPE_PRESSURE,
    500);

void CreateObjects(container &object) noexcept
{

    object.push_back(std::ref(s1));
    object.push_back(std::ref(s2));
    object.push_back(std::ref(s3));
    object.push_back(std::ref(s4));
    object.push_back(std::ref(s5));
}

bool ReadingAbove25(container &object)
{
    // check whether empty or not
    if (object.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    int count = 0;
    for (refPointer &value : object)
    {
        if (value.get()->reading() > 25)
        {
            count++;
        }
    }
    if (count == object.size())
    {
        return 1;
    }

    return 0;
}

int CountOfSensorOfType(container &object, SensorType sensorType)
{
    // check whether empty or not
    if (object.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    int count = 0;
    for (refPointer& value : object)
    {
        if (value.get()->type() == sensorType)
            count++;
    }

    return count;
}

container ConditionOnReadingAndType(container &object)
{
    // check whether empty or not
    if (object.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    container store;
    for (refPointer& value : object)
    {
        if (value.get()->type() == SensorType::TYPE_PRESSURE &&
            value.get()->reading() > 15)
        {
            store.push_back(value.get());
        }
    }

    return store;
}
