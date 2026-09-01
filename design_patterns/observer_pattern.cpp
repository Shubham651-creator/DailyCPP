#include <iostream>
#include <vector>
#include <algorithm>

class Observer
{
public:
    virtual void update(int value) = 0;

    virtual ~Observer() = default;
};


class Subject
{
private:
    int value = 0;

    std::vector<Observer*> observers;

public:

    void attach(Observer* observer)
    {
        observers.push_back(observer);
    }

    void detach(Observer* observer)
    {
        observers.erase(
            std::remove(
                observers.begin(),
                observers.end(),
                observer
            ),
            observers.end()
        );
    }

    void setValue(int newValue)
    {
        value = newValue;

        notify();
    }

private:

    void notify()
    {
        for (Observer* observer : observers)
        {
            observer->update(value);
        }
    }
};


class Logger : public Observer
{
public:
    void update(int value) override
    {
        std::cout << "Logger: value = " << value << '\n';
    }
};


class Display : public Observer
{
public:
    void update(int value) override
    {
        std::cout << "Display: value = " << value << '\n';
    }
};


class Alarm : public Observer
{
public:
    void update(int value) override
    {
        if (value > 100)
        {
            std::cout << "Alarm: HIGH VALUE!\n";
        }
    }
};


int main()
{
    Subject subject;

    Logger logger;
    Display display;
    Alarm alarm;

    subject.attach(&logger);
    subject.attach(&display);
    subject.attach(&alarm);

    subject.setValue(50);

    std::cout << "----\n";

    subject.setValue(150);

    return 0;
}