#include <iostream>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include <numeric>
#include "Employee.h"

using Pointer = std::shared_ptr<Employee>;

int main()
{
    // single key attached to a single object
    std::unordered_map<int, Pointer> data{
        {101, std::make_shared<Employee>(101, 2000.0f, "Shubham")},
        {102, std::make_shared<Employee>(102, 3000.0f, "awale1")},
        {103, std::make_shared<Employee>(101, 3000.0f, "awale2")},
        {101, std::make_shared<Employee>(101, 3000.0f, "awale3")},
    };

    // try_emplace : if duplicate key present, it discard
    data.try_emplace(101, std::make_shared<Employee>(104, 6000.0f, "Shubham2"));

    // emplace() ----> insert() : store in container
    data.emplace(107, std::make_shared<Employee>(103, 2000.0f, "Shubham3"));
    data.emplace(101, std::make_shared<Employee>(105, 2000.0f, "Shubham5"));

    // insert :
    data.insert({109, std::make_shared<Employee>(109, 6000.0f, "Shubham9")});

    data[108] = std::make_shared<Employee>(108, 6000.0f, "Shubham8");

    // overlapping on previous duplicate key
    data.insert_or_assign(101, std::make_shared<Employee>(
                                   111, 6000.0f, "insert_or_assign:shubam"));

// ========================================================================

    for (auto &[k, v] : data)
    {
        std::cout << "Key = " << k
                  << "\tValue address = " << v << "\n"
                  << "Value = " << *v << "\n\n";
    }

    /*
        check total number of rows(buckets) of hash table
    */
    std::cout << "Total bucket(current rows) = " << data.bucket_count()
              << "\n\n";

    /*
        check which row (bucket) a particular key(hash value)
        belong to
    */
    std::cout << "Slot(row/bucket) for 101 key :" << data.bucket(101)
              << "\n\n";

    /*
        check total number of elments in the unordered map
    */
    std::cout << "total element in unordered map :" << data.size()
              << "\n\n";

    /*
        STL algo(count_if) : count instance with salary over
        90000.0f
    */
    int count = std::count_if(
        data.begin(), // pair of key and value (first position)
        data.end(),   // last position iterator(outside container)

        //  [](const std::pair<int, Pointer> &obj1)
        //  [](std::pair<const int, Pointer> &obj1)
        [](std::pair<int, Pointer> &&obj1)
        {
            return obj1.second.get()->salary() > 900.0f;
        });

    std::cout << "the count of instance with salary over 90000 : "
              << count << "\n\n";

    /*
        total salary
    */
    std::cout << "Total salary of objects :"
              << std::accumulate(
                     data.begin(),
                     data.end(),
                     0.0f,
                     [](float ans, auto &obj)
                     {
                         return ans + obj.second.get()->salary();
                     })
              << "\n\n";

    /*
        check if all employee have salary above 9000.0f
    */
    std::cout << "Check all employee salary above 9000.0f: "
              << std::all_of(
                     data.begin(),
                     data.end(),
                     [](auto &obj)
                     {
                         return obj.second.get()->salary() > 900.0f;
                     })
              << "\n\n";
}