#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


class Queue {
    public:
    int data;
    Node *front;
    int sz;

    Queue() {
        front = NULL;
        tail = NULL;
        sz = 0;
    }
    void push(int data){
        Node *node = new Node(data);
        front->next = node;
        if(front==NULL){
            front = tail = node;
        }else{
            tail->next = node;
            front = node;
        }
        sz++
    }
    void pop(){
        if(front!=NULL){
            front=front->next;
            sz--;
        }
    }
    int front(){
        if(front!=NULL){
            return front->data;
        }else{
            return 0;
        }

    }
    int size(){
        return this->sz;
    }
    bool empty(){
        return (sz==0);
    }

    
    ;



};


int main() {
   Queue q;
   q.push(10);
   q.push(20);
   q.push(15);
   q.push(1);

   cout << q.front() << endl; // 1
   q.pop();
   q.pop();
   cout << q.front() << endl; // 20
   cout << q.size() << endl;
   cout << q.empty();

    return 0;
}