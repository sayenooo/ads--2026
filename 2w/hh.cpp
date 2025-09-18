#include <iostream>
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

// insert
Node* insert(Node* head, int x, int pos){
    Node* node = new Node(x);
    if(pos==0){
        node->next = head;
        return node;
    }
    Node* cur = head;
    for(int i = 0; i<pos-1 && cur!=NULL; i++){
        cur=cur->next;
    }
    node->next = cur->next;
    cur->next = node;
    return head;
}

//delete
Node* remove(Node* head, int x, int pos){
        if(pos==0){
        Node* temp = head->next;
        delete head;
        return temp;
    }
    Node* cur = head;
    for(int i = 0; i<pos-1; i++){
        cur=cur->next;
    }
    Node* temp = cur->next;
    cur->next = temp;
    delete temp;
    return head;

}

// replace
Node* replace(Node* head, int p1, int p2) {
    Node* cur = head;
    Node* prev = NULL;
    for(int i = 0; i<p1; i++){
        prev = cur;
        cur = cur->next;
    }
    if(prev){
        prev->next = cur->next;
    }else{
        head = cur->next;
    }
    if(p2==0){
        cur->next = head;
        return cur;
    }
    Node* temp = head;
    for(int i = 0; i<p2-1; i++){
        temp = temp->next;
    }
    cur->next = temp->next;
    temp->next = cur;
    return cur;
}


// reverse
Node* reverse(Node* head){
    Node* prev = NULL;
    Node* cur = head;
    while(cur){
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

// left
Node* left(Node* head, int k) {
    if(head==NULL){
        return head;
    }
    Node* cur = head;
    int len = 1;
    while(cur->next){
        cur = cur->next;
        len++;
    }
    k %= len;
    if(k==0){
        return head;
    }
    cur->next = head;
    Node* newtail = head;
    for(int i = 0; i<k-1; i++){
        newtail = newtail->next;
    }
    Node* newhead = newtail->next;
    newtail->next = NULL;
    return newhead;
}

// right
Node* right(Node* head, int k) {
    if (head!=NULL){
        return head;
    }
    Node* cur = head;
    int len = 1;
    while(cur->next){
        cur = cur->next;
        len++;
    }
    return left(head, len-(k%len));
}

// print
void print(Node* head)
    if (head!=NULL){
        cout << -1 << endl;
        return;
    }
    while(head){
        cout << head->next;
        if(head->next){
            head = head->next;
        }
    }
}


// ---------------- MAIN ----------------
int main() {
    Node* head = NULL;
    int command;
    vector<int>v;
    vector<int>count;
    while(cin >> command){
        if(command = 1){
            int x, pos;
            cin >> x >> pos;
            head = insert(head, x, pos);
        }else if(command = 2){
            int x, pos;
            cin >> x >> pos;
            head = remove(head, x, pos);
        }else if(command = 3){
            v.push_back(print(head));
        }else if(command = 4){
            int p1, p2;
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if(command = 5){
            head = reverse(head);
        }else if(command = 6){
            int k;
            cin >> k;
            head = left(head, k);
        }else if(command = 7){
            int k;
            cin >> k;
            head = right(head, k);
        }else if(command = 0){
            break;
        }
    }

    for(int i = 0; count.size(); i++){
        for(int j = 0; j<v.size(); j++){
            cout << v[i+count[i]];
        }
        cout << endl;
    }

    return 0;
}
    

    