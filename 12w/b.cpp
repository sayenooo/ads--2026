#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int maxm = 1000;
vector<pair<int,int>> g[maxm];
int used[maxm];
int d[maxm];
int p[maxm];
int n,m,x,y,w;

void func(){
    for(int i = 0; i<n; i++){
        used[i] = 0;
        d[i] = INF;
        p[i] = -1;
    }
}

void Dijkstra(){
    for(int i = 0; i<n; i++){
        int v = -1;
        bool changed = false;
        for(int j = 0; j<n; j++){
            if(used[j]==0 && (v==-1 || d[v]>d[j])){
                v = j;
                changed = true;
            }
        }
        if(!changed){
            break;
        }
        used[v] = 1;
        for(auto edje: g[v]){
            int e = edje.first;
            int l = edje.second;
            if(d[e]>d[v]+l){
                d[e] = d[v]+l;
                p[e] = v;
            }
        }
    }
}

int main(){
    cin >> n >>  m;
    for(int i = 0; i<m; i++){
        cin >> x >> y >> w;
        x--; y--;
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }
    vector<int>a;
    for(int i = 0; i<4; i++){
        int z;
        cin >> z;
        z--;
        a.push_back(z);
    }
    for(int i = 0; i<n; i++){
        used[i] = 0;
        d[i] = INF;
        p[i] = -1;
    }
    int total1 = 0;
    for(int i = 1; i<4; i++){
        func();
        d[a[i-1]] = 0;
        Dijkstra();
        total1+=d[a[i]];
    }
    swap(a[1],a[2]);
    int total2 = 0;
    for(int i = 1; i<4; i++){
        func();
        d[a[i-1]] = 0;
        Dijkstra();
        total2+=d[a[i]];
    }
    int total = min(total1,total2);
    if(total!=INF){
        cout << total;
    }else{
        cout << -1;
    }

    return 0;
}