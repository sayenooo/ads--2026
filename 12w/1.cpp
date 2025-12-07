#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m,x,y,w,a,b;
vector<vector<pair<int,int>>> g; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;         

    for (int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        x--; y--;           
        g[x].push_back({y, w});
        g[y].push_back({x, w}); 
    }

    cin >> a >> b;
    a--; b--;

    vector<int> d(n, INF);
    vector<int> used(n, 0);

    d[a] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (v == -1 || d[j] < d[v])) {
                v = j;
            }
        }
        if (v == -1 || d[v] == INF){
            break;
        }
        used[v] = 1;

        for (auto edge : g[v]) {
            int u = edge.first;
            int w = edge.second;
            if (d[u] > d[v] + w) {
                d[u] = d[v] + w;
            }
        }
    }

    if (d[b] == INF){
        cout << -1;
    }
    else{
        cout << d[b];
    }

    return 0;
}