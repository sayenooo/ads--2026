//DFS

#include <bits/stdc++.h>
using namespace std;

const int maxm = 1000;
vector<int> g[maxm];
int used[maxm];
int n,m,x,y;

void DFS(int v){
    used[v] = 1;
    for(int i = 0; i<g[v].size(); i++){
        int u = g[v][i];
        if(used[u]==0){
            DFS(u);
        }
    }
}
int components(){
    for(int i = 0; i<n; i++){
        used[i] = 0;
    }
    int total = 0;
    for(int i = 0; i<n; i++){
        if(used[i]==0){
            DFS(i);
            total++;
        }
    }
    return total;
    
}

int main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cout << components();

    return 0;
}