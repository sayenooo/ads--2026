#include <bits/stdc++.h>
using namespace std;

const int maxm = 100005;
int p[maxm];
int r[maxm];
vector<pair<int, pair<int, int>>> g;
int n, m;
vector<long long> min_edge;

int find(int v) {
    if (p[v] == v) return v;
    return p[v] = find(p[v]);
}

void uniony(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    
    if (r[u] > r[v]) {
        p[v] = u;
    } else if (r[u] < r[v]) {
        p[u] = v;
    } else {
        p[v] = u;
        r[u]++;
    }
}

int main() {
    ios::sync_with_stdio(false);    cin.tie(nullptr);
    
    cin >> n >> m;
    
    min_edge.resize(n, LLONG_MAX);
    
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        
        for (int j = x; j < y; j++) {
            if (w < min_edge[j]) {
                min_edge[j] = w;
            }
        }
    }
    
    for (int i = 0; i < n - 1; i++) {
        if (min_edge[i] != LLONG_MAX) {
            g.push_back({min_edge[i], {i, i + 1}});
        }
    }
    
    for (int i = 0; i < n; i++) {
        p[i] = i;
        r[i] = 0;
    }
    
    sort(g.begin(), g.end());
    
    long long total = 0;
    for (auto& edge : g) {
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        
        if (find(u) != find(v)) {
            uniony(u, v);
            total += w;
        }
    }
    cout << total;
    
    return 0;
}