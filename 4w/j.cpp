#include <bits/stdc++.h>
using namespace std;

vector<int> result;

void build(vector<int> &v, int l, int r) {
    if (l > r) return;
    int mid = (l + r) / 2;   
    result.push_back(v[mid]);
    build(v, l, mid - 1);    
    build(v, mid + 1, r);    
}

int main() {
    int n;
    cin >> n;
    int size = (1 << n) - 1;  
    vector<int> v(size);
    for (int i = 0; i < size; i++) cin >> v[i];

    sort(v.begin(), v.end());  
    build(v, 0, size - 1);   

    for (int x : result) cout << x << " ";
    return 0;
}
