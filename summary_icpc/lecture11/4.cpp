// DFS - is Bipartite?

#include <bits/stdc++.h>
using namespace std;

const int maxm = 1000;
vector<int> g[maxm];
int color[maxm];
int n,m,x,y;

bool DFS(int v, int c){
    color[v] = c;

    for(int i = 0; i<g[v].size(); i++){
        int u = g[v][i];
        if(color[u]==0){
            if(DFS(u,3-c)){
                return true;
            }
        }else if(color[u]==c){
            return true;
        }
    }
    return false;
}
bool has_bi(){
    for(int i = 0; i<n; i++){
        color[i] = 0;
    }
    for(int i = 0; i<n; i++){
        if(color[i]==0){
            if(DFS(i,1)){
                return false;
            }
        }
    }
    return true;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cout << has_bi();

    return 0;
}