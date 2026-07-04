#include<iostream>
#include<algorithm>
#include<numeric>
#include"Customer.h"
#include"Account.h"
#include"Functionalities.h"
 
using RefType = std::reference_wrapper<Pointer>;
using CustomerPointer = std::shared_ptr<Customer>;

int main(){

    CustomerContainer customer;
    AccountContainer account;

    CreateObjects(customer, account);

    for(std::shared_ptr<Customer>& value : customer){
        std::cout<<*value<<'\n';
    }

     Operation(
        customer, 
        [](CustomerContainer& data){ std::cout<<"\n\nOperation print : "<<*data[0];});

    /*
        & : it capture all surrounding variables
    */

     Operation(customer, 
     [](CustomerContainer& data){
        float ans = std::accumulate(
            data.begin(), 
            data.end(), 
            0.0f,
            [](float total, CustomerPointer& obj){return total+ obj->age();}
        );
     }
    );

    Operation(
        customer,
        [](CustomerContainer& data){
            auto min = std::min_element(
                data.begin(), 
                data.end(),
                [](CustomerPointer& c1, CustomerPointer& c2){return c1->age() < c2->age();}
            );

            std::cout<<"\n\nminimum element by age customer object = \n"<<**min<<'\n';
        }
    );
    
}