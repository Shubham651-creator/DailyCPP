class Node{
    public:
        int data;
        Node* next;
    
        explicit Node(int data){
            this->data = data;
            next = nullptr;
        }
};
