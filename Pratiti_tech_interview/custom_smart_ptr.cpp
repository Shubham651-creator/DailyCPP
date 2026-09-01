#include<iostream>

class smart_ptr{

    private:
        int *ptr;

    public:
        smart_ptr(int *p = nullptr): ptr(p){}

        // Disable copy constructor and operator
        smart_ptr(const smart_ptr&) = delete;
        smart_ptr& operator=(const smart_ptr&) = delete;

        smart_ptr(smart_ptr&& other) noexcept{
            std::cout<<"in move constructor\n";
            this->ptr = other.ptr;
            other.ptr = nullptr;
        }

        smart_ptr& operator=(smart_ptr&& other) noexcept{
            std::cout<<"in move operator\n";

            if(this == &other){
                *this;
            }

            delete ptr;

            this->ptr = other.ptr;
            other.ptr = nullptr;

            return *this;
        }

        int& operator*(){
            return *ptr;
        }

        int* operator->(){
            return ptr;
        }

        int* get(){
            return ptr;
        }

        ~smart_ptr(){
            delete ptr;
        }

};

int main(){

    smart_ptr p1(new int(10));
    smart_ptr p2(new int(20));

    p2 = std::move(p1);

    std::cout<< *p2 << std::endl; 
    

    bool isValid = p1.get() ? true: false;
    std::cout<< isValid << std::endl;

    return 0;
}