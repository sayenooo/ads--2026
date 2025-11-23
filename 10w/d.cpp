#include <bits/stdc++.h>
using namespace std;

const int maxm = 500005;
const int INF = 1e9;
vector<int> g[maxm];
int d[maxm];
queue<int> q;

int main(){
    int n, m, num;
    cin >> n >> m >> num;
    fill(d, d + n + 1, INF);
    
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    for(int i = 0; i < num; i++){
        int pos, v;
        cin >> pos >> v;
        
        if(pos == 1){
            if(d[v] > 0){
                d[v] = 0;
                q.push(v);
            }
        } else {
            if(d[v] == INF){
                cout << -1 << "\n";
            } else {
                cout << d[v] << "\n";
            }
        }
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            
            for(int y : g[x]){
                if(d[y] > d[x] + 1){
                    d[y] = d[x] + 1;
                    q.push(y);
                }
            }
        }
    }
    
    return 0;
}