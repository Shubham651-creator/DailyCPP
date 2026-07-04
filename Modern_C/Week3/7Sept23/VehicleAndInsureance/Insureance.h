#ifndef INSUREANCE_H
#define INSUREANCE_H

#include <iostream>
#include "InsuranceType.h"

class Insureance
{
private:
    std::string insuranceId;
    float insuranceAmount;
    InsuranceType insuranceType;

public:
    Insureance() = delete;

    Insureance(const Insureance &) = delete;

    Insureance &operator=(Insureance &) = delete;

    Insureance(Insureance &&) = delete;

    Insureance &operator=(Insureance &&) = delete;

    Insureance(std::string id, float amount, InsuranceType type);

    // destructor
    ~Insureance() = default;

    std::string getInsuranceId() const { return insuranceId; }

    float getInsuranceAmount() const { return insuranceAmount; }

    InsuranceType getInsuranceType() const { return insuranceType; }

    friend std::ostream &operator<<(std::ostream &os, const Insureance &rhs);
};

std::string DisplayInsuranceType(InsuranceType type);

#endif // INSUREANCE_H
