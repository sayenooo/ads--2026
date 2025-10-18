#include <bits/stdc++.h>
using namespace std;

void quicksort(vector<int> &a, int l, int r){
    int i = l, j = r;
    int p = a[(l + r) / 2];
    while (i <= j) {
        while (a[i] < p) i++;
        while (a[j] > p) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j) quicksort(a, l, j);
    if (i < r) quicksort(a, i, r);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    quicksort(a, 0, n - 1);
    quicksort(b, 0, m - 1);

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            i++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }

    return 0;
}