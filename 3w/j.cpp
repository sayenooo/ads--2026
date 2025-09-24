#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h;
    cin >> n >> h;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    long long low = 1;
    long long high = *max_element(v.begin(), v.end());
    long long ans = high;

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long sumn = 0;

        for (int i = 0; i < n; i++) {
            sumn += (v[i] + mid - 1) / mid;
        }

        if (sumn <= h) { 
            ans = mid;      
            high = mid - 1;
        } else {
            low = mid + 1; 
        }
    }

    cout << ans << endl;
    return 0;
}
