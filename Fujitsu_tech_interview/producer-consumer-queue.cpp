// producer-consumer queue

#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>

using namespace std;

class Queue{
    
    private:
        int* data;
        int front;
        int rear;
        
    public:
    
        Queue(){
            data = new int[10];
            front = 0;
            rear = 0;
        }
        
        void enque(int value){
            if(front == rear+1){
                cout<< "Queue is full" <<endl;
            }
            data[++rear] = value;
        }
        
        int deque(){
            if(rear == -1 || front == -1){
                cout<<"Queue is empty" << endl;
                return -1;
            }
            ++front;
            
            return data[front];
        }
        
        void display(){
            for(int i= front+1; i<=rear; i++){
                cout<< data[i] <<endl;
            }
        }
        
        int* getData(){
            return data;
        }
};

mutex mt;
static int sum = 0;

void add(int a, int b){
    
    mt.lock();
    //critical section
    int temp = a+b;
    sum +=temp;
    
    mt.unlock();
}

void sub(int a, int b){
    
    mt.lock();
    //critical section
    int temp = a-b;
    sum -=temp;
    
    mt.unlock();
}

int main(){
    
    Queue producer;
    producer.enque(1);
    producer.enque(2);
    producer.enque(3);
    
    cout<<"After filling data" <<endl;
    producer.display();
    
    producer.deque();
    cout<<"After deque or delete the data" << endl;
    producer.display();
    
    std::thread t1(&add,4,3);
  
    t1.join();
    cout<<"The add of a,b: "<< sum << endl;
    
    std::thread t2(&sub, 4,3);
    t2.join();
    cout<<"The sub of a,b: "<< sum << endl;
    
    return 0;
}