#include <bits/stdc++.h>
using namespace std;

const int maxm = 100;
vector<int> g[maxm];
int d[maxm];
int used[maxm];
queue<int> q;
int n;

void bsf(int v, int u){
    q.push(v);
    used[v] = 1;
    d[v] = 0;
    while(!q.empty()){
        int x = q.front();
        for(int i = 0; i<g[x].size(); i++){
            int y = g[x][i];
            if(used[y]==0){
                used[y] = 1;
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
        q.pop();
    }
}

int main(){
    cin >> n;
    int a[n][n];
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> a[i][j];
            if(a[i][j]==1){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    int v, u;
    cin >> v >> u;
    bsf(v-1, u-1);
    if(d[u-1]>0){
        cout << d[u-1];
    }else{
        cout << -1;
    }


    return 0;
}