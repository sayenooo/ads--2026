#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<char> ss;

    if (s.size() == 0) {
        cout << "YES";
    }

    for (char c : s) {
        if (!ss.empty() && ss.top() == c) {
            ss.pop();
        } else {
            ss.push(c);
        }
    }

    if (ss.empty()) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
