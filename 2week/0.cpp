#include <iostream>
using namespace std;

// Definition of a Node in a singly linked list
class Node {
  
public:
    // Data part of the node
    int data;

    // Pointer to the next node in the list
    Node* next;

    // Constructor to initialize the node with data
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

 

    // Создадим узлы вручную:
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "Singly Linked List: ";
    Node* cur = head;
    while (cur != nullptr) { // идем по цепочке
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;


    // 🔹 2. Doubly Linked List (двусвязный список)
    // Каждый узел хранит:
    //  - данные (value)
    //  - указатель на следующий (next)
    //  - указатель на предыдущий (prev)
    //
    // Плюсы:
    //  - Можно двигаться в обе стороны
    //  - Удаление/вставка проще, чем в обычном Linked List
    // Минусы:
    //  - Занимает больше памяти (доп. указатель)

    struct DNode {
        int data;
        DNode* prev;
        DNode* next;
        DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
    };

    // Создадим двусвязный список: 5 <-> 15 <-> 25
    DNode* head2 = new DNode(5);
    DNode* second = new DNode(15);
    DNode* third = new DNode(25);

    head2->next = second;
    second->prev = head2;
    second->next = third;
    third->prev = second;

    cout << "Doubly Linked List forward: ";
    DNode* cur2 = head2;
    while (cur2 != nullptr) { // прямой обход
        cout << cur2->data << " ";
        cur2 = cur2->next;
    }
    cout << endl;

    cout << "Doubly Linked List backward: ";
    cur2 = third;
    while (cur2 != nullptr) { // обратный обход
        cout << cur2->data << " ";
        cur2 = cur2->prev;
    }
    cout << endl;

    return 0;
}
