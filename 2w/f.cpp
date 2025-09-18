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
int main(){
    Queue q;
    int n,pos,a;
    cin >> n;
    vector<int>v(n);
    for(int i = 0; i<n; i++){
        cin >> v[i];
    }
    cin >> a;
    cin >> pos;
    for(int i = 0; i<n; i++){
        if(i==pos){
            q.push(a);
        }
        q.push(v[i]);
    }
    while(!q.empty()){
        cout << q.f() << " ";
        q.pop();
    }



    return 0;
}