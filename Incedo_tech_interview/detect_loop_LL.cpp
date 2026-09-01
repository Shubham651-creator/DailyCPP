// Floyd's Cycle - finding algorithm
// Tortoise-hare Algorithm

#include<iostream>
#include "linked_list.h"

bool detect_loop(Node* head){
    Node* slow= head, * fast  = head;

    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }
    return false;
}

void displayLinkedListData(Node* head){
    Node* temp = head;
    do{
        if(detect_loop(head)){
            std::cout<< "Loop detected. Cannot display the linked list." << std::endl;
            return;
        }

        std::cout<<temp->data<<" ";
        temp = temp->next;

    }while(temp != nullptr);
    std::cout<< std::endl;
}


int main(){
    Node* head = new Node(1);
    head->next = new Node(2);   
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;
    
    if(detect_loop(head)){
        std::cout<<"Loop detected in the linked list"<<std::endl;
    }
    else{
        std::cout<<"No loop detected in the linked list"<<std::endl;
    }

    displayLinkedListData(head);

    return 0;
}