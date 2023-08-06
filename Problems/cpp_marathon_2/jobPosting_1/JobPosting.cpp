#include <iostream>
#include "JobPosting.h"

JobPosting::JobPosting()
{
    jobTitle = "CPP Developer";
    company = "KPIT";
    jobLocation = "Pune";
    jobDescription = "We required the 9+ experienced\n";
}

JobPosting::JobPosting(std::string title, std::string companys, std::string location, std::string description)
    : jobTitle(title), company(companys), jobLocation(location), jobDescription(description)
{
}

JobPosting::~JobPosting()
{
    //std::cout << "Called() jobPosting destructor\n";
}

void JobPosting::display()
{
    std::cout << "JOB Details :\n"
              << "Job Name = " << jobTitle
              << "\nCompany= " << company
              << "\nJob location = " << jobLocation
              << "\nJob Description = " << jobDescription
              << "\n\n";
}

void JobPosting::accept()
{
    std::cout << "Enter Job details : \n"
              << "Enter job title = ";
    std::cin >> jobTitle;
    std::cout << "\nEnter Company = ";
    std::cin >> company;
    std::cout << "\nEnter Job location =";
    std::cin >> jobLocation;
    std::cout << "\nEnter job description = ";
    std::cin >> jobDescription;
    std::cout << "\n\n";
}
