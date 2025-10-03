#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; 

    vector<vector<int>> v(n+1); 

    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back(y); 
    }
    queue<pair<int,int>> q;
    q.push({1, 1}); //node and level

    vector<int> l(n+1,0);
    int mx = 0;

    while (!q.empty()) {
        pair<int,int> p = q.front();
        int node = p.first;
        int level = p.second;
        q.pop();
        l[level]++;
        mx = max(mx,l[level]);
        for(int child: v[node]){
            q.push({child,level+1});
        }
    }

    cout << mx;
}
