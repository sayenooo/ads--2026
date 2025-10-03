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

    bool found(string s){
        Node* node = root;
        for(char c: s){
            if(node==NULL){
                return false;
            }
            if(c=='L'){
                node=node->left;
            }else{
                node=node->right;
            }
        }
        return node!=NULL;

    }


};

int main(){
    Tree tree;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        tree.insert(x);
    }
    for(int i = 0; i<m; i++){
        string s;
        cin >> s;
        if(tree.found(s)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}