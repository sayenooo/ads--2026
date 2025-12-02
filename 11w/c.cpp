#include <bits/stdc++.h>
using namespace std;

const int maxm = 1005;
int p[maxm];
int r[maxm];

int find(int v){
    if(p[v]==v){
        return v;
    }
    p[v] = find(p[v]);
    return p[v];
}
void uniony(int u, int v){
    u = find(u);
    v = find(v);
    if(r[u]<r[v]){
        p[u] = v;
    }else if(r[u]>r[v]){
        p[v] = u;
    }else{
        p[u] = v;
        r[v]++;
    }
}
int main(){
    int n, m, a, b;
    cin >> n >> m;
    cin >> a >> b;
    vector<pair<int,pair<int,int>>> g;
    for(int i = 0; i<m; i++){
        int x,y,z,t;
        string type;
        cin >> type >> x >> y >> z;
        x--; y--;
        if(type=="both"){
            t = min(z*a, z*b);
        }
        if(type=="big"){
            t = z*a;
        }
        if(type=="small"){
            t = z*b;
        }
        g.push_back({t,{x,y}});
    }
    sort(g.begin(),g.end());
    for(int i = 0; i<n; i++){
        p[i] = i;
        r[i] = 0;
    }
    int total = 0;
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