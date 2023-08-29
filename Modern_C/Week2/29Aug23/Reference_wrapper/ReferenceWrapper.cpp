// reference wrapper : Reference of Project must be exist or valid for Employee

#include<iostream>
#include<functional>
#include<vector>
#include<memory>
#include"Project.h"
#include"Employee.h"

using Pointer = std::unique_ptr<Employee>;
using Container = std::vector<Pointer>;
using ProjectContainer = std::vector<std::unique_ptr<Project>>;

void CreateObject(Container& data, ProjectContainer& project_data){
    project_data.push_back(std::make_unique<Project>("HONDA"));

    data.push_back(
        std::make_unique<Employee>(101, 20000.0f, std::ref(project_data[0]))
    );
}

int main(){

    Container data;
    ProjectContainer project_data;

    CreateObject(data, project_data);

}