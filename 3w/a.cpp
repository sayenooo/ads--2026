#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int row, col;
    cin >> row >> col;
    map<int, pair<int, int>> mp;
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            int x;
            cin >> x;
            mp[x] = {i,j};
        }
    }
    
    for(int i = 0; i<n; i++){
        if(mp.find(a[i])!=mp.end()){
            cout << mp[a[i]].first << " " << mp[a[i]].second << endl;
        }else{
            cout << -1 << endl;
        }
        
    }
    
    
    return 0;
    
}