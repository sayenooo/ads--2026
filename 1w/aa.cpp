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

    void push_front(int data){
        Node* node = new Node(data);
        if(tail==NULL){
            tail=front=node;
        }else{
            node->next=front;
            front=node;
        }
        sz++;
    }
    void push_back(int data){
        Node* node = new Node(data);
        if(front==NULL){
            tail=front=node;
        }else{
            tail->next=node;
            tail=node;
        }
        sz++;
        
    }
    void pop_front(){
        if(front==NULL){
            front=tail=NULL;
        }
        else{
            Node* temp = front;
            if(front==tail){
                front=tail=NULL;
            }
            else{
                front=front->next;
                delete temp;
            }
            sz--;
        }
    }
    void pop_back(){
        if(tail==NULL){
            front=tail=NULL;
        }
        else{
            if(front==tail){
                front=tail=NULL;
            }
            else{
                Node* temp = front;
                while(temp->next!=tail){
                    temp=temp->next;
                }
                tail=temp;
                temp = tail->next;
                delete temp;
            }
            sz--;
        }
    }
    int f(){
        return front->data;
    }
    int back(){
        return tail->data;
    }
    int size(){
        return sz;
    }
    bool empty(){
        return (sz==0);
    }
};


int main() {
    int t;
    cin >> t;

    Deque dq;
    while(t--){
        int x;
        cin >> x;
        for(int i = x; i>=1; i--){
            dq.push_front(i);
            for(int j = 1; j<=i; j++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        while(!dq.empty()){
            cout << dq.f() << " ";
            dq.pop_front();
        }
        cout << endl;
    }
    return 0;
}