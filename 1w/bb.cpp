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
        if(front==NULL){
            front=tail=NULL;
        }else{
            Node* temp = front;
            front=front->next;
            delete temp;
            sz--;
        }
    }
    int size(){
        return sz;
    }
    int f(){
        return front->data;
    }
    bool empty(){
        return (sz==0);
    }
};

class Stack{
    public:
    Node *top;
    int sz;

    Stack(){
        top = NULL;
        sz = 0;
    }

    void push(int data){
        Node* node = new Node(data);
        node->next=top;
        top=node;
        sz++;
    }

    void pop(){
        if(top==NULL){
            top=NULL;
        }else{
            Node* temp = top;
            top=top->next;
            delete temp;
            sz--;
        }
    }
    int size(){
        return sz;
    }
    int t(){
        return top->data;
    }
    bool empty(){
        return (sz==0);
    }
};

int main()
{
    int n, x;
    cin >> n;
    Stack st;
    vector<int> v;
    Queue ans;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() && st.t() > v[i])
        {
            st.pop();
        }
        if (st.empty())
            ans.push(-1);
        else
            ans.push(st.t());
        st.push(v[i]);
    }
    while (!ans.empty())
    {
        cout << ans.f() << ' ';
        ans.pop();
    }
    return 0;
}