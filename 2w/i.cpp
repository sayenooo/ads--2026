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

class Deque{
    public:
    Node* front;
    Node* tail
    ;
    int sz;

    Deque(){
        front = NULL;
        tail = NULL;
        sz = 0;
    }
    void push_back(string data){
        Node* node = new Node(data);
        if(front==NULL){
            tail=front=node;
        }
        else{
            tail->next=node;
            tail=node;
        }
        sz++;
    }
    void push_front(string data){
        Node* node = new Node(data);
        if(tail==NULL){
            front=tail=node;
        }
        else{
            node->next=front;
            front=node;
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
    string f(){
        return front->data;
    }
    string t(){
        return tail->data;
    }
    int size(){
        return sz;
    }
    bool empty(){
        return (sz==0);
    }
};


int main(){
    Deque dq;
    vector<string>v;
    string command;
    while(cin >> command){
        if(command=="add_front"){
            string s;
            cin >> s;
            dq.push_front(s);
            v.push_back("ok");
        }else if(command=="add_back"){
            string s;
            cin >> s;
            dq.push_back(s);
            v.push_back("ok");
        }else if(command=="erase_front"){
            if(!dq.empty()){
                string a = dq.f();
                dq.pop_front();
                v.push_back(a);
            }else{
                v.push_back("error");
            }
        }else if(command=="erase_back"){
            if(!dq.empty()){
                string a = dq.t();
                dq.pop_back();
                v.push_back(a);
            }else{
                v.push_back("error");
            }
        }else if(command=="front"){
            if(!dq.empty()){
                v.push_back(dq.f());
            }else{
                v.push_back("error");
            }
        }else if(command=="back"){
            if(!dq.empty()){
                v.push_back(dq.t());
            }else{
                v.push_back("error");
            }
        }else if(command=="clear"){
            while(!dq.empty()){
                dq.pop_front();
            }
            v.push_back("ok");
        }else if(command=="exit"){
            v.push_back("goodbye");
            break;
        }
    }

    for(int i = 0; i<v.size(); i++){
        cout << v[i] << endl;
    }



    return 0;
}