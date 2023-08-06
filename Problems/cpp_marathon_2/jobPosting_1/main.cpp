#include <iostream>
#include "JobPosting.h"

// Array which hold the N objects
JobPosting arr[10];

void addJobPosting(int numberOfJobs)
{
    std::cout << "Add Job posting here...\n";
    for (int jobs = 0; jobs < numberOfJobs; jobs++)
    {
        arr[jobs].accept();
    }
}

// searching by company
void searchByCompany(int numberOfJobs)
{

    std::string company;
    std::cout << "Enter company name for searching....\n";
    std::cin >> company;

    for (int jobs = 0; jobs < numberOfJobs; jobs++)
    {
        if (arr[jobs].getCompany() == company)
        {
            std::cout << "The company " << company << " is found here\n";
            return;
        }
    }
    throw "The company is NOT found\n";
}
// searching by job Location
void searchByLocation(int numberOfJobs)
{

    std::string location;
    std::cout << "Enter company name for searching....\n";
    std::cin >> location;

    for (int jobs = 0; jobs < numberOfJobs; jobs++)
    {
        if (arr[jobs].getJobLocation() == location)
        {
            std::cout << "The job location " << location << " is found here\n";
            return;
        }
    }

    throw "The location is NOT found\n";
}

// menu driven approch
void showMenu(int numberOfJobs)
{

    int choice;

    do
    {
        std::cout << "Menu : 1.Add job posting; 2.search by company; 3.search by job location; 4.Display ;5.exit\n";
        std::cin >> choice;

        switch (choice)
        {
        case 1: // add job posting
            addJobPosting(numberOfJobs);
            break;

        case 2: // searching by company
            // exception handling using try-catch block
            try
            {
                searchByCompany(numberOfJobs);
            }
            catch (const char *msg)
            {
                std::cerr << "Error :" << msg << '\n';
            }

            break;

        case 3: // searching by job Location
                // exception handling using try-catch block
            try
            {
                searchByLocation(numberOfJobs);
            }
            catch (const char *msg)
            {
                std::cerr << "Error :" << msg << '\n';
            }

            break;

        case 4:
            std::cout << "display job posting here...\n";
            for (int jobs = 0; jobs < numberOfJobs; jobs++)
            {
                arr[jobs].display();
            }
        case 5:
            exit(0);
            break;
        }

    } while (1);
}

// client code
int main()
{

    int numberOfJobs;
    std::cout << "\nEnter number of jobs = ";
    std::cin >> numberOfJobs;
    showMenu(numberOfJobs);

    return 0;
}