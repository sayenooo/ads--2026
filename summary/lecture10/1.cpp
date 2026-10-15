// BFS 
// distnace from 1 V to anothers

#include <bits/stdc++.h>
using namespace std;

const int maxm = 1000;
vector<int> g[maxm];
int used[maxm];
int d[maxm];
queue<int> q;
int n,m,x,y;

void BFS(int a){
    for(int i = 0; i<n; i++){
        used[i] = 0;
        d[i] = -1;
    }

    used[a] = 1;
    d[a] = 0;
    q.push(a);

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0; i<g[v].size(); i++){
            int u = g[v][i];
            if(used[u]==0){
                used[u] = 1;
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }

    for(int i = 0; i<n; i++){
        cout << d[i] << " ";
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    BFS(0);
}
