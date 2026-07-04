#include<iostream>
#include<functional>

struct Employee
{
    int _id;
    std::reference_wrapper<std::string> _project;

    Employee(int id, std::reference_wrapper<std::string> project)
    : _id(id), _project(project){}
};

int main(){

    std::string name = "honda";
    struct Employee e1(101, std::ref(name));

    std::cout<<e1._id<<" and "<<e1._project.get()<<'\n';
}
