#include <bits/stdc++.h>
using namespace std;

const int maxm = 100005;
const int INF = 1e9;
vector<pair<int,int>> g[maxm];
int used[maxm];
int p[maxm];
int d[maxm];
int n,m,x,y,w;

void mst(int start){
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
    int a[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            w = a[i] + a[j];
            g[i].push_back({j,w});
            g[j].push_back({i,w});
        }
    }
    mst(0);
    int total = 0;
    for(int i = 0; i<n; i++){
        total+=d[i];
    }
    cout << total;
    return 0;
}