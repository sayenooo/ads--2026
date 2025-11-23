#include <bits/stdc++.h>
using namespace std;

//cycle detection in undirected graph
const int maxm = 100000;
vector<int> g[maxm];
int used[maxm];
int st[maxm];
int n,m,x,y;

// cycle detection in directed graph
bool dfs(int v){
    used[v] = 1;
    st[v] = 1;

    for(int i = 0; i<g[v].size(); i++){
        int u = g[v][i];
        if(used[u]==0){
            if(dfs(u)){
                return true;
            }
        }
        if(st[u]==1){
            return true;
        }
    }
    st[v]=0;
    return false;
}
bool has_cycle(){
    for(int i = 1; i<=n; i++){
        used[i] = 0;
        st[i] = 0;
    }
    for(int i = 1; i<=n; i++){
        if(used[i]==0){
            if(dfs(i)){
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
        g[x].push_back(y);
    }
    bool a = false;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<g[i].size(); j++){
            int val = g[i][j];
            g[i][j] = 0;
            if(!has_cycle()){
                a = true;
            }
            g[i][j] = val;
        }
        if(a){
            cout << "YES";
            break;
        }
    }
    if(!a){
        cout << "NO";
    }

    return 0;
}