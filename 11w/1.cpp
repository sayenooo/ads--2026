#include <bits/stdc++.h>
using namespace std;

const int maxm = 1000;
vector<pair<int,pair<int,int>>> g;
int p[maxm];
int r[maxm];
int n,m,x,y,w;

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

int main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> x >> y >> w;
        x--;
        y--;
        g.push_back({w,{x,y}});
    }
    sort(g.begin(),g.end());
    for(int i = 0; i<n; i++){
        p[i] = i;
    }
    int total = 0;
    for(int i = 0; i<n; i++){
        int u = g[i].second.first;
        int v = g[i].second.second;
        int l = g[i].first;
        if(find(u)!=find(v)){
            uniony(u,v);
            total += l;
        }
    }

    return 0;
}