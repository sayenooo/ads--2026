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
    map<int,int> mp;
    int l = 0;
    void inorder(Node* node, int l){
        int sum = 0;
        if(node==NULL){
            return;
        }
        mp[l] += node->data;
        sz = max(sz,l);
        inorder(node->left, l+1);
        inorder(node->right, l+1);
    }
    int level(){
        return sz;
    }
    void print(){
        for(auto it:mp){
            cout << it.second << " ";
        }
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
    tree.inorder(tree.root,0);
    cout << tree.level() + 1 << endl;
    tree.print();
    

}