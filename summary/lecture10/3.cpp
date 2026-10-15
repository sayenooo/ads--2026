// adjacency list

#include <bits/stdc++.h>
using namespace std;

const int maxm = 1000;
vector<int> g[maxm];
int n,m,x,y;

int main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 0; i<n; i++){
        cout << i+1 << ":";
        for(int j = 0; j<g[i].size(); i++){
            cout << g[i][j]+1 << " ";
        }
        cout << endl;
    }
    
    return 0;
}