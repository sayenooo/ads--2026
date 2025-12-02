#include <bits/stdc++.h>
using namespace std;

const int maxm = 100;
const int INF = 1e9;
int n;
vector<pair<int,int>> g[maxm];
int used[maxm];
int d[maxm];
int p[maxm];

void prim(int start){
    for(int i = 0; i<n; i++){
        p[i] = -1;
        used[i] = 0;
        d[i] = INF;
    }
    d[start] = 0;
    for(int i = 0; i<n; i++){
        int v = -1;
        for(int j = 0; j<n; j++){
            if(used[j]==0 && (v==-1 || d[j]<d[v])){
                v = j;
            }
        }
        if(d[v]==INF){
            break;
        }
        used[v] = 1;
        for(auto edje: g[v]){
            int u = edje.first;
            int l = edje.second;
            if(used[u]==0 && (d[u]>l)){
                d[u] = l;
                p[u] = v;
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int c;
            cin >> c;
            if(j <= i) continue;
            if(c == 0){
                g[i].push_back({j,0});
                g[j].push_back({i,0});
            } else {
                g[i].push_back({j,c});
                g[j].push_back({i,c});
            }
        }
    }
    prim(0);
    int total = 0;
    for(int i = 0; i<n; i++){
        total+=d[i];
    }
    cout << total;
    return 0;
}