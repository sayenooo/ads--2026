//MST - Kruskal минимум спаннинг три
// find - unit

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int maxm = 1000;
vector<pair<int,pair<int,int>>> g;
int r[maxm];
int p[maxm];
int n,m,x,y,w;

int find(int u){
    if(p[u]==u){
        return u;
    }
    p[u] = find(p[u]);
    return p[u];
}
void uniony(int v, int u){
    u = find(u);
    v = find(v);
    if(r[u]>r[v]){
        p[v] = u;
    }else if(r[u]<r[v]){
        p[u] = v;
    }else{
        p[u] = v;
        r[v]++;
    }
}
void Kruskal(){
    int total = 0;
    for(int i = 0; i<n; i++){
        r[i] = 0;
        p[i] = i;
    }
    for(auto edje: g){
        int v = edje.second.first;
        int u = edje.second.second;
        int l = edje.first;
        if(find(u)!=find(v)){
            uniony(u,v);
            total+=l;
        }
    }
    cout << total;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> x >> y >> w;
        x--; y--;
        g.push_back({w,{x,y}});
    }
    sort(g.begin(), g.end());

    Kruskal();
}






