#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* right;
    Node* left;
    int data;

    Node(int data){
        left = NULL;
        right = NULL;
        this->data=data;
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

    Node* insert(Node* node, int data){
        if(node==NULL){
            return new Node(data);
        }else if(node->data<data){
            node->right = insert(node->right, data);
        }else{
            node->left = insert(node->left, data);
        }
        return node;
    }
    void insert(int data){
        root = insert(root, data);
    }

    Node* found(Node* node, int data){
        if(node==NULL){
            return NULL;
        }if(node->data<data){
            return found (node->right, data);
        }else if(node->data>data){
            return found (node->left, data);
        }else{
            return node;
        }
    }
    int count(Node* node){
        if(node==NULL){
            return 0;
        }
        return 1 + count(node->left) + count(node->right);
    }
    int size(int data){
        Node* dd = found(root, data);
        return count(dd);
    }


};

int main(){
    Tree tree;
    int n, m;
    cin >> n;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        tree.insert(x);
    }
    cin >> m;
    cout << tree.size(m);
}