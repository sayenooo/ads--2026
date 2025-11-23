#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1005][1005];

bool check(int x, int y, int z) {
    return a[x][y] && a[y][x] &&
           a[x][z] && a[z][x] &&
           a[y][z] && a[z][y];
}

int main(){
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i<m; i++){
        int x,y,z;
        cin >> x >> y >> z;
        x--;
        y--;
        z--;
        if(check(x,y,z)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }




    return 0;
}