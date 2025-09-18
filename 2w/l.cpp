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
    Node* front;
    Node* tail;
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
            if(front==NULL) tail=NULL;
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
    vector<int>v;

    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    for(int i = 0; i<n; i++){
        int count = 0;
        for(int j = i; j<n; j++){
            count+=v[j];
            if(!q.empty() && q.f()<count){
                q.pop();
                q.push(count);
            }else if(q.empty()){
                q.push(count);
            }
        }
    }


    while(!q.empty()){
        cout << q.f() << " ";
        q.pop();
    }

    return 0;
}