#include <iostream>
#include <cstring>

class UnderflowException : public std::exception
{
    char message[100];

public:
    UnderflowException(const char *p)
    {
        strcpy(message, p);
    }
    char *getMessage()
    {
        return message;
    }
};

class OverflowException : public std::exception
{
    char message[100];

public:
    OverflowException(const char *p)
    {
        strcpy(message, p);
    }
    char *getMessage()
    {
        return message;
    }
};

template <class T>
class MyStack
{
private:
    T *arr;
    int size, top;

public:
    MyStack(int s);
    MyStack();

    T pop();
    void push(T element);

    bool isFull()
    {
        return top == size - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

template <class T>
MyStack<T>::MyStack()
{
    size = 2;
    top = -1;
    arr = new T[size];
}

template <class T>
MyStack<T>::MyStack(int s)
{
    size = s;
    top = -1;
    arr = new T[size];
}

template <class T>
void MyStack<T>::push(T element)
{
    if (!isFull())
        arr[++top] = element;
    else
        throw OverflowException("Stack is full \n");
}

template <class T>
T MyStack<T>::pop()
{
    if (!isEmpty())
        return arr[top--];
    else
        throw UnderflowException("Stack is empty.\n");
}

int main()
{
    MyStack<int> stack;

    try
    {
        stack.push(10);
        stack.push(20);
        stack.push(30);
    }
    catch (UnderflowException uobj)
    {
        std::cout << uobj.getMessage() << '\n';
    }
    catch (OverflowException overObj)
    {
        std::cout << overObj.getMessage() << '\n';
    }

    return 0;
}
