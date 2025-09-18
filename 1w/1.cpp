#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int> > q;

int f(int a, int b) {
    q.push(make_pair(a, 0));

    while (!q.empty()) {
        int x = q.front().first;
        int d = q.front().second;

        
        q.pop();
    }
    return 0;
}

int main() {
    int a;
    cin >> a;
    for(int i = 0; i<a; i++){
        int x;
        cin >> x;
        func(x,i);
    }

    vector<int> result;
    result.push_back(b);
    int t = b;
    while (used[t] != t) {
        t = used[t];
        result.push_back(t);
    }

    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << " ";

    return 0;
}
 