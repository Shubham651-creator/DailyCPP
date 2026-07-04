#include <iostream>
#include "MyQueue.h"
#include <cstring>

class OverflowException : public std::exception
{
private:
    char message[100];

public:
    OverflowException()
    {
    }
    OverflowException(const char *p)
    {
        strcpy(message, p);
    }
    ~OverflowException()
    {
    }

    char *getMessage()
    {
        return message;
    }
};
