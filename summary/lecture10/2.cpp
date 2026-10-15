// adjacency list

#include <bits/stdc++.h>
using namespace std;

const int maxm = 1000;
int a[maxm][maxm];
int n,m,x,y;

int main(){
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            a[i][j] = 0;
        }
    }

    for(int i = 0; i<m; i++){
        cin >> x >> y;
        x--; y--;
        a[x][y] = 1;
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}