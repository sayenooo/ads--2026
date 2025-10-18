/*как запустить код

g++ 0.cpp -o 0
0.exe

        
*/
// Lecture 1: Complexity, Memory, Factorization, Stack, Queue, Deque

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;

int main() {
    // 1. Сложность алгоритмов (Big-O)
    // O(n) — линейный поиск в массиве
    vector<int> arr = {1, 5, 7, 10, 15};
    int x = 10;
    bool found = false;
    for (int el : arr) { // O(n)
        if (el == x) {
            found = true;
            break;
        }
    }
    cout << "Element found: " << found << endl;

    // 2. Разложение числа на простые множители (O(√n))
    int n = 84;
    cout << "Prime factorization of " << n << ": ";
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 1) cout << n;
    cout << endl;

    // 3. Стек (LIFO)
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Stack top: " << st.top() << endl; // 30
    st.pop();
    cout << "After pop, top: " << st.top() << endl; // 20

    // 4. Очередь (FIFO)
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Queue front: " << q.front() << endl; // 1
    q.pop();
    cout << "After pop, front: " << q.front() << endl; // 2

    // 5. Дек (двусторонняя очередь)
    deque<int> dq;
    dq.push_back(10);  // [10]
    dq.push_front(5);  // [5, 10]
    dq.push_back(20);  // [5, 10, 20]
    cout << "Deque front: " << dq.front() << ", back: " << dq.back() << endl; // 5, 20
    dq.pop_front(); // [10, 20]
    dq.pop_back();  // [10]
    cout << "After pops, front: " << dq.front() << endl; // 10

    return 0;
}
