#include<iostream>
#include "linked_list.h"

void displayLinkedListData(Node* head){
    Node* temp = head;
    do{
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != nullptr);
    std::cout<< std::endl;
}

Node* reverseTheLL(Node* head){
    // Reverse the Linked list
    Node* current = head;
    Node* prev = nullptr;
    Node* temp = nullptr;

    while(current != nullptr){
        temp = current->next;
        current->next = prev;
        
        prev = current;
        current = temp;
    }

    return prev;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);   
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    displayLinkedListData(head);

    displayLinkedListData(reverseTheLL(head));

    return 0;
}