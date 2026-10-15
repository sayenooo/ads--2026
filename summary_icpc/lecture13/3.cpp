//ssp - Bellman-Ford 
// dijjkstra neg no cycle

#include <bits/stdc++.h>
using namespace std;

struct edje{
    int u,v,w;
};

const int INF = 1e9;
const int maxm = 1000;
int d[maxm];
int p[maxm];
int n,m,a,b;

void Ford(vector<edje> g){
    for(int i = 1; i<=n; i++){
        bool changed = false;
        for(auto &e: g){
            if(d[e.u]!=INF && d[e.v]>d[e.u]+e.w){
                d[e.v] = d[e.u]+e.w;
                changed = true;
            }
        }
        if(!changed){
            break;
        }
    }
    //cycle detection
    for(auto &e: g){
        if(d[e.u]!=INF && d[e.v]>d[e.u]+e.w){
            break;
        }
    }
}
int main(){
    cin >> n >> m;
    vector<edje> g(m);
    for(auto &e: g){
        cin >> e.u >> e.v >> e.w;
    }
    for(int i = 1; i<=n; i++){
        d[i] = INF;
        p[i] = -1;
    }
    cin >> a >> b;
    d[a] = 0;
    Ford(g);
    cout << d[b];


    return 0;
}
