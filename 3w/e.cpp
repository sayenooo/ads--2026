#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, idx;
    cin >> n >> idx;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int val = max(x2, y2);
        v.push_back(val);
    }

    sort(v.begin(), v.end());

    cout << v[idx-1];

    return 0;
}
