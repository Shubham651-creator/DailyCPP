#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include "MemoryType.h"

class System
{
private:
    MemoryType _memory;
    float _disk_space;
    std::string _allocation_number;

public:
    // disable default constructor
    System() = delete;

    // disable copy constructor
    System(const System &) = delete;

    // disable copy assignment operator
    System &operator=(System &) = delete;

    // disable move constructor
    System(System &&) = delete;

    // disable move assignment operator
    System &operator=(System &&) = delete;

    // parameterized constructor
    System(MemoryType memory, float space, std::string allocation);

    // destructor
    ~System() = default;

    MemoryType memory() const { return _memory; }

    float diskSpace() const { return _disk_space; }

    std::string allocationNumber() const { return _allocation_number; }

    friend std::ostream &operator<<(std::ostream &os, const System &rhs);
};

std::string DisplayMemoryType(MemoryType type);

#endif // SYSTEM_H
