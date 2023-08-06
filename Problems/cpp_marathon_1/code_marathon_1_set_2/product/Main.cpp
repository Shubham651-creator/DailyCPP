#include<iostream>
#include"Product.h"

int amount[3]={0};

void calculateBill(Product product[3]){
    //calculate final bill and display it
    int totalsum =0 ;
    std::cout << "Number\tproductName\tQuantity\tRate\tCategory\tamount\n" ;

    for(int productCount =0 ; productCount<3; productCount++){
        product[productCount].display();
        totalsum += product[productCount].getTotalAmount();
    }

    std::cout<<"The final bill amount is "<<totalsum<<"\n";

}

//client code
int main(){
    Product product[3];

    std::cout<<"Enter your product requirement .\n";
    for(int productCount=0 ; productCount<3; productCount++){
        product[productCount].accept();
    }

    //calcute the final bill
    calculateBill(product);

    return 0;
}