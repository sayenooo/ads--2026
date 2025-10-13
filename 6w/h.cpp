#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<char> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    char c;
    cin >> c;

    char ans = v[0];
    for (int i = 0; i < n; i++) {
        if (v[i] > c) {
            ans = v[i];
            break;
        }
    }

    cout << ans;
    return 0;
}
