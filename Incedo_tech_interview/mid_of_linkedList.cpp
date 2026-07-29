// Find the mid element of linked list

#include<iostream>
using namespace std;

// Linked list Node
class Node
{
    public:
    int data;
    Node* next;

    Node(int value){
        data= value;
        next = nullptr;
    }
};

// display the all elements of linked list
void display(Node* head){
    Node* temp = head;

    while(temp != nullptr){
        cout<< temp->data << " -->";
        temp = temp->next;
    }

    cout<< "NULL"<<endl;
}

//Return Middle Node of linked list
Node* findMiddle(Node* head){

    if(head == nullptr){
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){

    Node* head = new Node(10);
    head->next = new Node(20);

    Node* N2 = head->next;
    N2->next = new Node(30);

    Node* N3 = N2->next;
    N3->next = new Node(40);

    N3->next->next = new Node(50);

    display(head);

    cout<<"The middle element is "<< findMiddle(head)->data << endl;

    return 0;
}
