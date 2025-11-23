#include <bits/stdc++.h>
using namespace std;

const int maxm = 100005;
int used[maxm];
int d[maxm];
vector<int> a[maxm];
queue<int> q;

void bsf(int v){
    q.push(v);
    used[v] = 1;
    d[v] = 0;
    while(!q.empty()){
        int x = q.front();
        for(int i = 0; i<a[x].size(); i++){
            int y = a[x][i];
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
    int n, m;
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    bsf(u);
    if(d[v]>0){
        cout << "YES";
    }else{
        cout << "NO";
    }



    return 0;
}