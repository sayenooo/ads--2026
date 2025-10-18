#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k; // читаем n и k
    vector<int> v(n);

    long long sumn = 0;
    int mx = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sumn += v[i];
        mx = max(mx, v[i]);
    }

    long long l = mx;
    long long r = sumn;
    long long res = r;

    while (l <= r) {
        long long mid = (l + r) / 2;
        int block = 1;
        long long cur = 0;
        for (int i = 0; i < n; i++) {
            if (cur + v[i] > mid) {
                block++;
                cur = v[i];
            } else {
                cur += v[i];
            }
        }

        if (block > k) {
            l = mid + 1;
        } else {
            res = mid;
            r = mid - 1;
        }
    }

    cout << res;
    return 0;
}
