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

    push(int data){
        Node* node = new Node(data);
        if(front==NULL){
            tail = front = node;
        }else{
            tail->next=node;
            tail=node;
        }
        sz++;
    }
    pop(){
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


int main(){
    Queue q;
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++){
        int x;
        cin >> x;
        if(i%2!=0){
            q.push(x);
        }
    }
    while(!q.empty()){
        cout << q.f() << " ";
        q.pop();
    }


    return 0;
}