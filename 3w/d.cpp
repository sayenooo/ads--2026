#include <bits/stdc++.h>
using namespace std;

long long func(vector<long long>& v, long long l, long long r) {
    if(l>r) return 0;
    long long left = lower_bound(v.begin(), v.end(), l) - v.begin();
    long long right = upper_bound(v.begin(), v.end(), r) - v.begin();
    return (long long)right - left;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    while (k--) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        cout << func(v, l1,r1) + func(v, l2,r2) - func(v, max(l1, l2), min(r1, r2)) << endl;
    }

    return 0;
}