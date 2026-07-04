#ifndef JOBPOSTING_H
#define JOBPOSTING_H

#include <iostream>

class JobPosting
{
private:
    std::string jobTitle;
    std::string company;
    std::string jobLocation;
    std::string jobDescription;

public:

    //default constructor
    JobPosting();

    //parameterized constructor
    JobPosting(std::string title, std::string companys, std::string location, std::string description);

    //destructor
    ~JobPosting();

    //display the job information
    void display();

    //take input of job data
    void accept();

    std::string getJobTitle() const { return jobTitle; }
    void setJobTitle(const std::string &jobTitle_) { jobTitle = jobTitle_; }

    std::string getCompany() const { return company; }
    void setCompany(const std::string &company_) { company = company_; }

    std::string getJobLocation() const { return jobLocation; }
    void setJobLocation(const std::string &jobLocation_) { jobLocation = jobLocation_; }

    std::string getJobDescription() const { return jobDescription; }
    void setJobDescription(const std::string &jobDescription_) { jobDescription = jobDescription_; }
};

#endif // JOBPOSTING_H
