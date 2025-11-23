#include <bits/stdc++.h>
using namespace std;

int const maxm = 100001;
vector<int> g[maxm];
int degrees[maxm];
int n,m,x,y;

int main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        degrees[y]++;
    }
    queue<int> q;
    for(int i = 0; i<n; i++){
        if(degrees[i]==0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        ans.push_back(x+1);
        for(int i = 0; i<g[x].size(); i++){
            int y = g[x][i];
            degrees[y]--;
            if(degrees[y]==0){
                q.push(y);
            }
        }
    }
    
    if(ans.size()==n){
        cout << "Possible" << endl;
        for(int i = 0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
    }else{
        cout << "Impossible";
    }

    return 0;
}