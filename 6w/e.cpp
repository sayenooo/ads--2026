#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> a[i][j];
        }
    }
    vector<int>b;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            b.push_back(a[j][i]);
        }
        sort(b.rbegin(), b.rend());
        for(int j = 0; j<n; j++){
            a[j][i] = b[j];
        }
        b.clear();
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}