#ifndef CHARGINGUNIT_H
#define CHARGINGUNIT_H

#include <iostream>
#include <variant>
#include <vector>
#include <array>

using variantVariable =
    std::variant<std::vector<float>, std::array<float, 5>>;

class ChargingUnit
{
private:
    std::string _id;
    float _rating_kw;
    variantVariable _last_5_discharged_units;
    float _capacity;
    float _cost_per_kw;

public:
    // default constructor disable
    ChargingUnit() = delete;

    // disable copy constructor
    ChargingUnit(const ChargingUnit &) = delete;

    // disable copy operator
    ChargingUnit &operator=(ChargingUnit &) = delete;

    // disable move constructor
    ChargingUnit(ChargingUnit &&) = delete;

    // disable move operator
    ChargingUnit &operator=(ChargingUnit &&) = delete;

    // parameterized constructor
    ChargingUnit(std::string id, float rating, variantVariable lastUnits,
                 float capacity, float costKw);

    // destructor
    ~ChargingUnit() = default;

    std::string id() const { return _id; }

    float ratingKw() const { return _rating_kw; }

    variantVariable last5DischargedUnits() const { return _last_5_discharged_units; }

    float capacity() const { return _capacity; }

    float costPerKw() const { return _cost_per_kw; }

    friend std::ostream &operator<<(std::ostream &os, const ChargingUnit &rhs);
};

#endif // CHARGINGUNIT_H
