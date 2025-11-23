#include <bits/stdc++.h>
using namespace std;


vector<int> g[100000];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int x, y;
        cin >> x >> y;
        g[y].push_back(x);
    }
    queue<int> q;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<g[i].size(); j++){
            if(g[i][j]==0){
                q.push(i);
            }
        }
    }
    vector<int> res;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        res.push_back(x);


        for(int i = 0; i<n; i++){
            for(int j = 0; j<g[i].size(); j++){
                if(g[i][j]==x){
                    g[i][j] = 0;
                    
                }
            }
            if(g[i].empty()){
                q.push(i);
            }
        }
    }
    
    cout << res.size() << endl;
    for(int i = 0; i<res.size(); i++){
        cout << res[i] << " ";
    }


    return 0;
}