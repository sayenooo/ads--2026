// BFS - path

#include <bits/stdc++.h>
using namespace std;

const int maxm = 1000;
vector<int> g[maxm];
int used[maxm];
int d[maxm];
int p[maxm];
queue<int> q;
int n,m,x,y;

void BFS(int v, int u){
    for(int i = 0; i<n; i++){
        used[i] = 0;
        d[i] = -1;
        p[i] = -1;
    }

    used[v] = 1;
    d[v] = 0;
    q.push(v);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i<g[x].size(); i++){
            int y = g[x][i];
            if(used[y]==0){
                used[y] = 1;
                d[y] = d[x] + 1;
                p[y] = x;
                q.push(y);
            }
        }
    }

    if(used[u]==0){
        cout << "no path";
        return;
    }
    vector<int> path;
    int a = u;
    while(a!=-1){
        path.push_back(a);
        a = p[a];
    }
    reverse(path.begin(),path.end());
    for(int i = 0; i<path.size(); i++){
        cout << path[i] << " ";
    }
    path.push_back(u);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    BFS(0,6);

    return 0;
}