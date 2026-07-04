#include "Functionalities.h"

// container which stores DataRecore instance
using dataRecordContainer = std::vector<std::shared_ptr<DataRecord>>;

// container which stores DateUnit instances
using dataUnitContainer = std::vector<std::shared_ptr<DataUnit>>;

// function pointer
using funcPointer = std::function<void(dataRecordContainer &)>;

void CreateObjects(dataRecordContainer &dataRecord, dataUnitContainer &dataUnit)
{
    dataUnit.push_back(std::make_shared<DataUnit>(101, DataUnitType::IN_HOUSE, 200.0f));
    dataUnit.push_back(std::make_shared<DataUnit>(102, DataUnitType::OUTSOURCED, 300.0f));
    dataUnit.push_back(std::make_shared<DataUnit>(103, DataUnitType::IN_HOUSE, 400.0f));
    dataUnit.push_back(std::make_shared<DataUnit>(104, DataUnitType::OUTSOURCED, 500.0f));
    dataUnit.push_back(std::make_shared<DataUnit>(105, DataUnitType::IN_HOUSE, 600.0f));

    std::vector<int> v1{1, 2, 3, 4, 5};
    std::vector<int> v2{11, 21, 31, 41, 51};
    std::vector<int> v3{12, 22, 32, 42, 52};
    std::vector<int> v4{13, 23, 33, 43, 53};
    std::vector<int> v5{14, 24, 34, 44, 54};

    dataRecord.push_back(std::make_shared<DataRecord>(std::ref(dataUnit[0]), v1, v1));
    dataRecord.push_back(std::make_shared<DataRecord>(std::ref(dataUnit[0]), v2, v4));
    dataRecord.push_back(std::make_shared<DataRecord>(std::ref(dataUnit[0]), v3, v2));
    dataRecord.push_back(std::make_shared<DataRecord>(std::ref(dataUnit[0]), v4, v1));
    dataRecord.push_back(std::make_shared<DataRecord>(std::ref(dataUnit[0]), v3, v5));
}

void HigherOrderFunction(dataRecordContainer &data, funcPointer &fns)
{
    //check whether data is empty
    if(data.empty()){
        throw std::runtime_error("Container is empty\n");
    }

    fns(data);
}

void SumOfDataProvided(dataRecordContainer &data)
{

    //check whether data is empty
    if(data.empty()){
        throw std::runtime_error("Container is empty\n");
    }

    // a. sum of Provided is more than sum of expected
    int sumProvided = 0;
    int sumExpected = 0;

    for (auto &value : data)
    {
        for (int record : value->dataValuesProvided())
        {
            sumProvided += record;
        }

        for (int record : value->dataValuesExpected())
        {
            sumExpected += record;
        }
    }

    for (auto &value : data)
    {
        if (sumProvided > sumExpected)
        {
            std::cout << *value << '\n';
        }
    }

    // b.  unit id of data unit is above 10
    for (auto &value : data)
    {
        if (value->dataUnit().get()->unitId() < 10)
        {
            std::cout << *value << '\n';
        }
    }
}

void MaxUnitId(dataRecordContainer &data)
{
    //check whether data is empty
    if(data.empty()){
        throw std::runtime_error("Container is empty\n");
    }

    int max = 0;
    for (auto &value : data)
    {
        if (max < value->dataUnit().get()->unitId())
        {
            max = value->dataUnit().get()->unitId();
        }
    }
}

void PrintInstanceForINHOUSE(dataRecordContainer &data)
{
    //check whether data is empty
    if(data.empty()){
        throw std::runtime_error("Container is empty\n");
    }

    for (auto &value : data)
    {
        if (value->dataUnit().get()->unitType() == DataUnitType::IN_HOUSE)
        {
            std::cout << *value << '\n';
        }
    }
}

void PrintOddInstances(dataRecordContainer &data)
{
    //check whether data is empty
    if(data.empty()){
        throw std::runtime_error("Container is empty\n");
    }
    
    int count = 1;
    for (auto &value : data)
    {
        if (count % 2 != 0)
        {
            std::cout << *value << '\n';
        }
    }
}
