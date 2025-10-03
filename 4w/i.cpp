#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    int data;

    Node(int data){
        this->data=data;
        right = left = NULL;
    }
};

class Tree{
    public:
    Node* root;
    int sz;

    Tree(){
        root = NULL;
        sz = 0;
    }
    map <int,int> mp;
    Node* insert(Node* node, int data){
        if(node==NULL){
            return new Node(data);
        }
        if(node->data>data){
            node->left = insert(node->left,data);
        }else if(node->data<data){
            node->right = insert(node->right,data);
        }
        return node;
    }
    void insert(int data){
        root = insert(root, data);
        mp[data]++;
    }
    void deletee(int data){
        mp[data]--;
    }
    void cnt(int data){
        cout << mp[data] << endl;
    }
};

int main(){
    Tree tree;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        string s;
        int x;
        cin >> s >> x;
        if(s=="insert"){
            tree.insert(x);
        }else if(s=="delete"){
            tree.deletee(x);
        }else if(s=="cnt"){
            tree.cnt(x);
        }
    }

    return 0;
}