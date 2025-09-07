#include <bits/stdc++.h>
using namespace std;

string process(string str) {
    stack <char> st;
    for (char c : str) {
        if (c == '#') {
            if (!st.empty()){
                st.pop();
            }
        } else {
            st.push(c);
        }
    }

    string res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    if (process(str1) == process(str2))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
