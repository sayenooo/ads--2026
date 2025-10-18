#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

// Insert node at position p (0-based)
Node* insert(Node* head, int x, int p) {
    Node* node = new Node(x);
    if (p == 0 || head == nullptr) {
        node->next = head;
        return node;
    }
    Node* cur = head;
    for (int i = 1; i < p && cur->next; i++) {
        cur = cur->next;
    }
    node->next = cur->next;
    cur->next = node;
    return head;
}

// Remove node at position p (0-based)
Node* remove(Node* head, int p) {
    if (!head) return nullptr;
    if (p == 0) {
        Node* tmp = head->next;
        delete head;
        return tmp;
    }
    Node* cur = head;
    for (int i = 1; i < p && cur->next; i++) {
        cur = cur->next;
    }
    if (cur->next) {
        Node* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
    }
    return head;
}

// Print list
void print(Node* head) {
    if (!head) {
        cout << -1 << endl;
        return;
    }
    while (head) {
        cout << head->val << (head->next ? " " : "");
        head = head->next;
    }
    cout << endl;
}

// Reverse list
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* cur = head;
    while (cur) {
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

// Cyclic shift left by x
Node* cyclic_left(Node* head, int x) {
    if (!head || !head->next) return head;
    int len = 1;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    x %= len;
    if (x == 0) return head;

    tail->next = head; // make it circular
    Node* newTail = head;
    for (int i = 0; i < x - 1; i++) newTail = newTail->next;
    Node* newHead = newTail->next;
    newTail->next = nullptr;
    return newHead;
}

// Cyclic shift right by x
Node* cyclic_right(Node* head, int x) {
    if (!head || !head->next) return head;
    int len = 1;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    x %= len;
    if (x == 0) return head;
    return cyclic_left(head, len - x);
}

int main() {
    Node* head = nullptr;
    while (true) {
        int command; cin >> command;
        if (command == 0) break;
        else if (command == 1) { // insert
            int x, p; cin >> x >> p;
            head = insert(head, x, p);
        } 
        else if (command == 2) { // remove
            int p; cin >> p;
            head = remove(head, p);
        }
        else if (command == 3) { // print
            print(head);
        }
        else if (command == 4) { // reverse
            head = reverse(head);
        }
        else if (command == 5) { // cyclic left
            int x; cin >> x;
            head = cyclic_left(head, x);
        }
        else if (command == 6) { // cyclic right
            int x; cin >> x;
            head = cyclic_right(head, x);
        }
    }
    return 0;
}
