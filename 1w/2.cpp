#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

template<typename T>
class Node {
    public:
    T data;
    Node<T> *next;

    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

int main() {
    Node<string> *n1 = new Node<string>("hello");
    Node<string> *n2 = new Node<string>("world");
    Node<string> *n3 = new Node<string>("test");
    n1->next = n2;
    n2->next = n3;
    cout << n1->next->next->data;
    return 0;
}