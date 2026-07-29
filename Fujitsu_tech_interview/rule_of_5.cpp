/*
    Demonstrate Rule of 5 .
*/

#include<iostream>

class Signal{
    
    private:
        int* data;
        size_t n;

    public:
        // Parameter constructor
        explicit Signal(size_t n){
            data = new int[n];
            this->n = n;
        }

        //1. Destructor
        ~Signal(){
            delete[] data;
        }

        //2. Copy constructor
        Signal(const Signal& other){
            this->n = other.n;
            this->data = new int[n];

            for(int i=0; i<other.n; i++){
                this->data[i] = other.data[i];
            }
        }

        //3. Copy assignment operator
        Signal& operator=(const Signal& other){
            if(this == &other){
                return *this;
            }

            int* temp = new int[other.n];
            for(int i=0; i<other.n; i++){
                temp[i] = other.data[i];
            }

            delete[] data;
            
            data = temp;
            n = other.n;

            return *this; //enable chaining rule
        }

        //4. Move constructor
        Signal(Signal&& other) noexcept{
            this->n = other.n;
            this->data = other.data;

            other.data = nullptr;
            other.n = 0;
        }

        //5. Move assignment operator
        Signal& operator=(Signal&& other) noexcept{
            if(this == &other){
                return *this;
            }

            int* temp = new int[other.n];
            for(int i=0; i<other.n; i++){
                temp[i] = other.data[i];
            }

            delete[] data;

            data = temp;
            n = other.n;

            other.data = nullptr;
            other.n = 0;

            return *this;
        }

        //Add the data
        void setData(int arr[]){
            for(int i=0; i<this->n; i++){
                this->data[i] = arr[i];
            }
        }

        //Display the data
        void display(){
            for(int i=0; i<this->n; i++){
                std::cout<<this->data[i]<<" ";
            }
            std::cout<<std::endl;
        }

};

int main(){
    Signal A(5);
    Signal B(6);

    int arrA[5] = {1,2,3,4,5};
    int arrB[6] = {6,7,8,9,10,11};
    
    A.setData(arrA);
    A.display();

    B.setData(arrB);
    B.display();
    
    Signal A1 = A; //copy constructor
    A1.display();

    B = A; // copy assignment
    B.display();

    Signal C = Signal(3); //move constructor
    //Signal C = std::move(3)

    B = Signal(8); //move operator
    B.display();

    return 0;

}