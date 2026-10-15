// DFS - cycle detection in undirected graph

#include <bits/stdc++.h>
using namespace std;

const int maxm = 1000;
vector<int> g[maxm];
int used[maxm];
int n,m,x,y;

bool DFS(int v, int parent){
    used[v] = 1;
    for(int i = 0; i<g[v].size(); i++){
        int u = g[v][i];
        if(used[u]==0){
            if(DFS(u, v)){
                return true;
            }
        }else if(u!=parent){
            return true;
        }
    }
    return false;
}
bool has_cycle(){
    for(int i = 0; i<n; i++){
        used[i] = 0;
    }
    for(int i = 0; i<n; i++){
        if(used[i] == 0){
            if(DFS(i,-1)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cout << has_cycle();
}