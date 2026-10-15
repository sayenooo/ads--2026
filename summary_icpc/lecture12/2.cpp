// MST - Prim - минимум спаннин три
// v = -1 used distance

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int maxm = 1000;
vector<pair<int,int>> g[maxm];
int used[maxm];
int d[maxm];
int p[maxm];
int n,m,x,y,w;

void Prim(){
    for(int i = 0; i<n; i++){
        used[i] = 0;
        d[i] = INF;
        p[i] = -1;
    }
    d[0] = 0;
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
        for(auto &edje: g[v]){
            int e = edje.first;
            int l = edje.second;
            if(used[e]==0 && d[e]>l){
                d[e] = l;
                p[e] = v;
            }
        }
    }
    int total = 0;
    for(int i = 0; i<n; i++){
        total+=d[i];
    }
    cout << total;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> x >> y >> w;
        x--; y--;
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }
    Prim();


    return 0;
}