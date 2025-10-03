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

    int count(Node* node){
        if(node==NULL){
            return 0;
        }
        int sumn = 0;
        if(node->left!=NULL && node->right!=NULL){
            sumn = 1;
        }
        return sumn + count(node->left) + count(node->right);
    }


};

int main(){
    Tree tree;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        tree.insert(x);
    }
    cout << tree.count(tree.root);
}