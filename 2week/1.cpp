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
        front=NULL;
        tail=NULL;
        sz=0;
    }
    void push(int data){
        Node* node = new Node(data);
        if(front==tail){
            front=tail=node;
        }else{
            tail->next=node;
            tail=node;
        }
        sz++;
    }
    void pop(){
        if(front==NULL){
            return;
        }else{
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
    int n,m;
    cin >> n >> m;
    vector<int>a;
    vector<int>b;
    int i = 0;
    int j = 0;
    while(i<n && j<m){
        cin >> a[i] >> b[j];
        if(a[i]<b[j]){
            q.push(a[i]);
        }else{
            q.push(b[j]);
        }
        i++;
        j++;
        
    }

    while(!q.empty()){
        cout << q.f() << " ";
        q.pop();
    }




    return 0;
}