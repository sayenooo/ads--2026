class Queue{
    public:
    Node *front;
    Node *tail;
    int sz;

    Queue(){
        front = NULL;
        tail = NULL;
        sz = 0;
    }
    void push(int data){
        Node* node = new Node(data);
        if(front==NULL){
            front=tail=node;
        }else{
            tail->next=node;
            tail=node;
        }
        sz++;
    }
    void pop(){
        if(front!=NULL){
            front=front->next;
            sz--;
        }
    }
    int f(){
        return front->data;
    }
    int size(){
        return sz;
    }
    bool empty(){
        return (sz==0);
    }
};

class Stack{
    public:
    Node *top;
    int sz;

    Stack(){
        top = NULL;
        sz = 0;
    }
    void push(int data){
        Node* node = new Node(data);
        node->next=top;
        top=node;
        sz++;
    }
    void pop(){
        if(top!=NULL){
            top=top->next;
            sz--;
        }
    }
    int f(){
        return top->data;
    }
    int size(){
        return sz;
    }
    bool empty(){
        return (sz==0);
    }
};

class Deque{
    public:
    Node *front;
    Node *tail;
    int sz;

    Deque(){
        front = NULL;
        tail = NULL;
        sz = 0;
    }
    void push_back(int data){
        Node* node = new Node(data);
        if(front==NULL){
            front=tail=node;
        }else{
            tail->next=node;
            tail=node;
        }
        sz++;
    }
    void push_front(int data){
        Node* node = new Node(data);
        node->next=front;
        front=node;
        if(tail==NULL){
            tail=node;
        }
        sz++;
    }
    void pop_front(){
        if(front==NULL){
            return;
        }
        else if(front==tail){
            front=tail=NULL;
        }
        else{
            Node *node = front;
            front=front->next;
        }
        sz--;
    }
    void pop_back(){
        if(tail==NULL){
            return;
        }
        else if(front==tail){
            front=tail=NULL;
        }
        else{
            Node *node = front;
            while(node->next!=tail){
                node = node->next;
            }
            tail=node;
            tail->next=NULL;
        }
        sz--;
    }
    int f(){
        return front? front->data: -1;
    }
    int size(){
        return sz;
    }
    bool empty(){
        return (sz==0);
    }
};