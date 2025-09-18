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

class Stack{
    public:
    Node* top;
    int sz;

    Stack(){
        top=NULL;
        sz = 0;
    }

    push(int data){
        Node* node = new Node(data);
        node->next=top;
        top=node;
        sz++;
    }
    pop(){
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


int main(){
    Stack q;
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