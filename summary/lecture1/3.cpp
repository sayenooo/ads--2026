// Deque

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
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

int main(){
    Deque q;
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++){
        int x;
        cin >> x;
        if(i%2!=0){
            q.push_back(x);
        }
    }
    while(!q.empty()){
        cout << q.f() << " ";
        q.pop_front();
    }


    return 0;
}