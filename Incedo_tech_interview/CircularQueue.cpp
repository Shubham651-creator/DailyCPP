#include<iostream>
using namespace std;

class CircularQueue{

    private:
        int *data;
        int front, rear, size, count;

    public:
        CircularQueue(int size){
            this->size = size;
            data = new int[size];
            front = -1;
            rear = -1;
            count = 0;
        }

        ~CircularQueue(){
            delete[] data;
        }

        bool isFull() const {
            return (front == (rear+1)%size);
        }

        void enqueue(int value){
            if(isFull()){
                cout<<"Queue is full"<<endl;
                return;
            }

            rear = (rear+1 )% size;
            data[rear] = value;
            count++;
        }

        bool isEmpty() const{
            return (front == rear);
        }

        void dequeue(){
            if(isEmpty()){
                cout<<"Queue is empty"<<endl;
                return ;
            }
             front = (front+1) % size;
            cout<<"Deleted: " << data[front] << endl;
           
            count--;
        }

        void display()
        {
            if (isEmpty())
            {
                cout << "Queue is Empty\n";
                return;
            }

            cout << "Queue: ";

            for (int i = 1; i <= count; i++)
            {
                cout << data[(front+i)%size] << " ";
            }

            cout << endl;
        }
};
int main(){

    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(60);

    q.display();

    return 0;
}