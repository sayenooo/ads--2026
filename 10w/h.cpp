#include <bits/stdc++.h>
using namespace std;

pair<int,int> get_first(int n, int m, int a[1005][1005]){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(a[i][j] == 1){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

int main(){
    int n,m;
    cin >> n >> m;
    int a[1005][1005];
    queue<pair<int,int>> q;

    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        for(int j = 0; j<m; j++){
            a[i][j] = s[j] - '0';
        }
    }

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    int count = 0;

    while(true){
        auto p = get_first(n, m, a);
        if(p.first == -1) break;

        count++;
        q.push(p);
        a[p.first][p.second] = 2;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;

            for(int i = 0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && a[nx][ny]==1){
                    a[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
        }
    }

    cout << count;
    return 0;
}
