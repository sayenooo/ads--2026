#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n][m];
    queue<pair<int,int>> q;
    int total = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0;  j<m; j++){
            cin >> a[i][j];
            if(a[i][j]==2){
                q.push({i,j});
            }
            if(a[i][j]==1){
                total++;
            }
        }
    }
    if(total==0){
        cout << 0;
        return 0;
    }
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int min = 0;
    while(!q.empty()){
        int sz = q.size();
        bool ok = false;
        while(sz--){
            auto it = q.front();
            int x = it.first;
            int y = it.second;
            q.pop();
            for(int i = 0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m){
                    continue;
                }
                if(a[nx][ny]==1){
                    q.push({nx,ny});
                    a[nx][ny] += 1;
                    ok = true;
                    total--;
                }
            }
        }
        if(ok){
            min++;
        }
    }
    if(total>0){
        cout << -1;
    }else{
        cout << min;
    }


    return 0;
}