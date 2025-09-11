#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> v;

    while (n--) {
        string str;
        cin >> str;

        bool ok = false; // флаг, подходит ли строка

        for (int i = 0; i < str.size(); i++) {
            int count = 0;
            int s = str[i] - '0'; // число из символа

            for (int j = 0; j < str.size(); j++) { // проверяем всю строку
                int ss = str[j] - '0';
                if (s < ss) count++;
            }

            if (count <= 2) {
                ok = true;
                break; // если нашли, можно выходить
            }
        }

        if (ok) v.push_back("yes");
        else v.push_back("no");
    }

    for (int k = 0; k < v.size(); k++) {
        cout << v[k] << endl;
    }

    return 0;
}
