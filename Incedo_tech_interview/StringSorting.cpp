//Write a program to arrange five names in alphabetacal order, 
// use function pointer, smart pointer and do not use STLs.
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

void arrangeNames(vector<unique_ptr<string>>& store)
{
    for (size_t i = 0; i < store.size() - 1; i++)
    {
        for (size_t j = i + 1; j < store.size(); j++)
        {
            if (*store[i] > *store[j])
            {
                swap(store[i], store[j]);
            }
        }
    }
}

int main()
{
    vector<unique_ptr<string>> input;

    input.push_back(make_unique<string>("shubham"));
    input.push_back(make_unique<string>("awale"));
    input.push_back(make_unique<string>("omkar"));
    input.push_back(make_unique<string>("rasika"));
    input.push_back(make_unique<string>("jay"));

    // Actual function pointer
    void (*func)(vector<unique_ptr<string>>&) = arrangeNames;

    func(input);

    for (const auto& s : input)
    {
        cout << *s << endl;
    }
}