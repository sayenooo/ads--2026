// cycle detection in derected graph

#include <bits/stdc++.h>
using namespace std;

const int maxm = 1000;
vector<int> g[maxm];
int used[maxm];
int st[maxm];
int n,m,x,y;

bool DFS(int v){
    used[v] = 1;
    st[v] = 1;

    for(int i = 0; i<g[v].size(); i++){
        int u = g[v][i];
        if(used[u]==0){
            if(DFS(u)){
                return true;
            }
        }else if(str[u]==1){
            return true;
        }
    }
    st[v] = 0;
    return false;
}

bool has_cycle(){
    for(int i = 0; i<n; i++){
        used[i] = 0;
        st[i] = 0;
    }
    for(int i = 0; i<n; i++){
        if(used[i]==0){
            if(DFS(i)){
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
    }
    cout << has_cycle();

    return 0;
}