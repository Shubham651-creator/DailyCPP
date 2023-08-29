#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>

class Project
{
private:
    std::string _name;

public:
    Project() = delete;
    Project(const Project &) = delete;
    Project(Project &&) = delete;
    Project &operator=(Project &) = delete;
    Project &operator=(Project &&) = delete;
    Project(std::string name);
    ~Project() = default;

    std::string name() const { return _name; }

    friend std::ostream &operator<<(std::ostream &os, const Project &rhs);
};

#endif // PROJECT_H
