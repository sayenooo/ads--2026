#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    string data;
    Node* next;
    Node(string data){
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
    void push(string data){
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
    string f(){
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
    int x;
    cin >> x;
    for(int xx = 0; xx<x; xx++){
        Queue q;    
        map<string,int> m;    
        int n;
        cin >> n;

        for(int i = 0; i<n; i++){
            string c;
            cin >> c;
            m[c]++;
            q.push(c);

            while(!q.empty() && m[q.f()] > 1){
                q.pop();
            }

            if(!q.empty()){
                cout << q.f() << " ";
            }else{
                cout << -1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
