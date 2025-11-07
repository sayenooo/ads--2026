#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node *next;
    Node *prev;
    string data;

    Node(string data){
        next = prev = NULL;
        this->data = data;
    }
};

class Linked{
    public:
    Node *front;
    Node *tail;
    int sz;

    Linked(){
        front = tail = NULL;
        sz = 0;
    }

    void push_front(string data){
        Node* node = new Node(data);
        if(front==NULL){
            front = tail = node;
        }else{
            front->prev = node;
            node->next = front;
            front = node;
        }
        sz++;
    }
    void push_back(string data){
        Node* node = new Node(data);
        if(front==NULL){
            front = tail = node;
        }else{
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        sz++;
    }
    void pop_front(){
        if(front==NULL){
            return;
        }else if(front==tail){
            Node* cur = front;
            front = tail = NULL;
            delete cur;
        }else{
            Node* cur = front;
            front = front->next;
            front->prev = NULL;
            delete cur;
        }
        sz--;
    }
    void pop_back(){
        if(front==NULL){
            return;
        }else if(front==tail){
            Node* cur = front;
            front = tail = NULL;
            delete cur;
        }else{
            Node* cur = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete cur;
        }
        sz--;
    }
    void insert(string data, int pos){
        if(pos>sz){
            return;
        }else if(pos==0){
            return push_front(data);
        }else if(pos==sz){
            return push_back(data);
        }else{
            Node* node = new Node(data);
            Node* cur = front;
            for(int i = 0; i<pos; i++){
                cur = cur->next;
            }
            Node* p = cur->prev;
            node->prev = p;
            node->next = cur;
            p->next = node;
            cur->prev = node;
            sz++;
        }
    }
    void delete_data(string data){
        Node* cur = front;
        while(cur!=NULL){
            if(cur->data==data){
                break;
            }
        }
        if(cur==NULL){
            return;
        }
        Node* p = cur->prev;
        Node* n = cur->next;
        p->next = n;
        n->prev = p;
        delete cur;
    }
    void delete_idx(int pos){
        if(pos>sz-1){
            return;
        }
        Node* cur = front;
        for(int i = 0; i<pos; i++){
            cur = cur->next;
        }
        Node* p = cur->prev;
        Node* n = cur->next;
        p->next = n;
        n->prev = p;
        delete cur;
    }
    void print(){
        Node* cur = front;
        while(cur!=NULL){
            cout << cur->data << " ";
            cur = cur->next;
        }
    }
    void rotate(int pos){
        for(int i = 0; i<pos; i++){
            push_back(front->data);
            pop_front();
        }
    }


};

int main() {
    Linked l;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        l.push_back(s);
    }
    l.rotate(m);
    l.print();

    return 0;
}
