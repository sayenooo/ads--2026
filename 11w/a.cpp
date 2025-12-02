#include <bits/stdc++.h>
using namespace std;

vector<int> p, r;

int find(int v){
    if(p[v]==v){
        return v;
    }
    p[v] = find(p[v]);
    return p[v];
}

void uniony(int v, int u){
    v = find(v);
    u = find(u);
    if(r[v]>r[u]){
        p[u] = v;
    }else if(r[v]<r[u]){
        p[v] = u;
    }else{
        p[u] = v;
        r[v]++;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vector<pair<long long, pair<int,int>>> g;
    vector<long long> best(n - 1, LLONG_MAX);

    for(int i = 0; i < m; i++){
        int l, r;
        long long w;
        cin >> l >> r >> w;
        l--; r--;

        for(int x = l; x < r; x++){
            best[x] = min(best[x], w);
        }
    }

    for(int i = 0; i < n - 1; i++){
        g.push_back({best[i], {i, i + 1}});
    }

    sort(g.begin(), g.end());
    p.resize(n);
    r.resize(n, 0);
    long long total = 0;
    for(int i = 0; i<n; i++){
        p[i] = i;
    }
    for(int i = 0; i<g.size(); i++){
        int u = g[i].second.first;
        int v = g[i].second.second;
        int l = g[i].first;
        if(find(u)!=find(v)){
            uniony(u,v);
            total += l;
        }
    }

    cout << total;

    return 0;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vector<pair<long long, pair<int,int>>> g;

    for(int i = 0; i < m; i++){
        int l, r;
        long long w;
        cin >> l >> r >> w;
        l--; r--;
        g.push_back({w,{l,r}});
        for(int x = l; x < r; x++){
            g.push_back({w,{x,x+1}});
        }
    }

    sort(g.begin(), g.end());
    p.resize(n);
    r.resize(n, 0);
    long long total = 0;
    for(int i = 0; i<n; i++){
        p[i] = i;
    }
    for(int i = 0; i<g.size(); i++){
        int u = g[i].second.first;
        int v = g[i].second.second;
        int l = g[i].first;
        if(find(u)!=find(v)){
            uniony(u,v);
            total += l;
        }
    }

    cout << total;

    return 0;
}
