#include<iostream>
class complex{
    private:
    int real, img;

    public:
    complex(int real, int img){
        this->real = real;
        this->img = img;
    }

    complex operator+(const complex& c){
        // complex c1(0,0);

        // c1.img = this->img + c.img;
        // c1.real = this->real + c.real;

        // return c1;

        return {this->img + c.img,this->real + c.real };
    }

    void display(){
        std::cout<< "real:" << real <<"\timg: "
        << img << std::endl;
    }
};

int main(){
    complex c1(1,2),c2(2,3);

    complex c3= c1+c2; // c2.operator+(c2)
    //(1+2, 2+3)

    c3.display();
}