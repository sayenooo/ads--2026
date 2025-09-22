#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long COUNT(const vector<long long>& arr, long long L, long long R) {
    if (L > R) return 0;
    auto left = lower_bound(arr.begin(), arr.end(), L);
    auto right = upper_bound(arr.begin(), arr.end(), R);
    return right - left;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    while (q--) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        long long res = COUNT(arr, l1, r1) + COUNT(arr, l2, r2) - COUNT(arr, max(l1, l2), min(r1, r2));

        cout << res << endl;
    }

    return 0;
}
