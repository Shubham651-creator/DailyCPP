#include<iostream>

class A{
    private:
         
    public:
        A() {
            std::cout<<"Constructor A:\n";
        }
        virtual void display(){
            std::cout<< "Base display\n";
        }

        virtual ~A(){
            std::cout<<"~A()\n";
        }
};

class B : public A{
    public:
        B() {
            std::cout<<"Constructor B:\n";
        }
        void display(){
            std::cout<< "Derived display\n";
        }
        ~B(){
            std::cout<<"~B()\n";
        }
};

int main(){
     
    A *a = new B();
    a->display();
    
    // dynamic cast - polymorphism
    B * b1 = static_cast<B*>(a);
    b1->display();
    
    A* pure_a = new A();
    B * b2 = dynamic_cast<B*>(pure_a);
    if(b2 != nullptr){
        b2->display();
    }else{
        std::cout<<"b2 is nullptr\n";
    }
    
    //accessing base class member function
    a->A::display();
    b2->A::display();

    delete a, b1, b2, pure_a;
 
    return 0;
}