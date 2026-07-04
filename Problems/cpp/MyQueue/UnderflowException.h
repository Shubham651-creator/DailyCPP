#include <iostream>
#include "MyQueue.h"
#include <cstring>

class UnderflowException : public std::exception
{
private:
    char message[100];

public:
    UnderflowException()
    {
    }
    UnderflowException(const char *p)
    {
        strcpy(message, p);
    }
    ~UnderflowException()
    {
    }

    char *getMessage()
    {
        return message;
    }
};
