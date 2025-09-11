#include <bits/stdc++.h>
using namespace std;

int prime(int n) {
    vector<int> v;

    for (int i = 2; i <= 20000; i++) {
        bool aa = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                aa = false;
                break;
            }
        }
        if (aa) {
            v.push_back(i);
        }
    }

    return v[n-1];
}

int main() {
    int n;
    cin >> n;
    cout << prime(n) << "\n";
}
