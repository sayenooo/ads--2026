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
        root = insert(root,data);
    }
    int sumn = 0;
    int sums(Node* node){
        if(node==NULL){
            return 0;
        }
        sums(node->right);
        sumn += node->data;
        cout << sumn << " ";
        sums(node->left);
        return sumn;
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
    tree.sums(tree.root);

    return 0;
}