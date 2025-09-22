#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;
    queue<int> q;
    while(x--){
        int y;
        cin >> y;
        q.push(y);
    }

    int n,m;
    cin >> n >> m;
    map<int,pair<int,int>> mp;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int y;
            cin >> y;
            mp[y] = {i,j};
        }
    }
    while(!q.empty()){
        int val = q.front();
        if(mp.find(val)!=mp.end()){
            auto res = mp[val];
            cout << mp[val].first << " " << mp[val].second << endl;
            q.pop();
        }else{
            cout << -1 << endl;
            q.pop();
        }
    }

    return 0;
    
}
