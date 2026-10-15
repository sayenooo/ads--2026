//ssp - Dijkstra - жадных алгоритм
// сьедать противников 

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int maxm = 1000;
vector<pair<int,int>> g[maxm];
int used[maxm];
int d[maxm];
int p[maxm];
int n,m,x,y,w,a,b;

void Dijkstra(){
    for(int i = 0; i<n; i++){
        int v = -1;
        bool changed = false;
        for(int j = 0; j<n; j++){
            if(used[j]==0 && (v==-1 || d[v]>d[j])){
                v = j;
                changed = true;
            }
        }
        if(!changed){
            break;
        }
        used[v] = 1;
        for(auto edje: g[v]){
            int e = edje.first;
            int l = edje.second;
            if(d[e]>d[v]+l){
                d[e] = d[v] + l;
                p[e] = v;
            }
        }
    }
    
}
int main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> x >> y >> w;
        x--; y--;
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }
    for(int i = 0; i<n; i++){
        d[i] = INF;
        used[i] = 0;
        p[i] = -1;
    }
    cin >> a >> b;
    a--; b--;
    d[a] = 0;
    Dijkstra();
    cout << d[b];
}