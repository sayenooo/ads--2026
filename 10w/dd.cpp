#include <bits/stdc++.h>
using namespace std;

const long long maxm = 500005;
const long long INF = 1e18;
vector<long long> g[maxm];
long long used[maxm];
long long d[maxm];
queue<long long> q;
long long n, m, num, x, y;

int main(){
    cin >> n >> m >> num;
    fill(d, d + n, INF);
    for(int i = 0; i<m; i++){
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 0; i<num; i++){
        long long pos,v;
        cin >> pos >> v;
        v--;
        if(pos==1){
            if(d[v]>0){
                d[v] = 0;
                used[v] = 1;
                q.push(v);
            }
        }
        if(pos==2){
            if(d[v]!=INF){
                cout << d[v] << endl;
            }else{
                cout << -1 << endl;
            }
        }
        while(!q.empty()){
            long long x = q.front();
            for(int i = 0; i<g[x].size(); i++){
                long long y = g[x][i];
                if(d[y]>d[x]+1){
                    d[y] = d[x] + 1;
                    q.push(y);
                }
            }
            q.pop();
            }
    }

    return 0;
}