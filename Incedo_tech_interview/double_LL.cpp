//Insert a given element in particular position in double Linked list.
#include <iostream>

class Node{

    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data){
            this->data = data;
            next = nullptr;
            prev = nullptr;
        };
};

void InsertElementAtIndex(int index, int data, Node* head){

    if(index < 0){
        return;
    }

    int i=0;
    while(head != nullptr){
        i++;
        if(i==index){
            Node* addNode = new Node(data);
            auto temp = head->next;
            head->next = addNode;
            addNode->prev = head;
            addNode->next = temp;
        }
        head = head->next;
    }

};

int main(){

Node* n1 = new Node(10);

Node* n2 = new Node(20);
n2->prev = n1;
n1->next = n2 ;

Node* n3 =new Node(30); 
n3->prev = n2;
n2->next = n3;

std::cout<<"Insert element in particular location: ";
int index, data=40;
std::cin>> index;
InsertElementAtIndex(index, data, n1 );

Node* head = n1;
while(head != nullptr){
    std::cout<< head->data << std::endl;
    head = head-> next;
}

return 0;
}