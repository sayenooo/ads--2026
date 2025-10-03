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
        }else if(node->data>data){
            node->left = insert(node->left, data);
        }
        return node;
    }
    void insert(int data){
        root = insert(root, data);
    }
    int d = 0;
    int inorder(Node* node){
        if(node==NULL){
            return 0;
        }
        int lh = inorder(node->left);
        int rh = inorder(node->right);
        d = max(d, lh + rh);
        return 1 + max(lh,rh);
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
    tree.inorder(tree.root);   
    cout << tree.d + 1; 

}