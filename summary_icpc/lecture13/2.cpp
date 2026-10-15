// ssp - Floyd-Warshall - через 3 вершину найти кратчайший путь
// треугольник

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int maxm = 1000;
int a[maxm][maxm];
int n,m,x,y,w;

void Floyd(){
    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            a[i][j] = INF;
        }
    }
    for(int i = 0; i<m; i++){
        cin >> x >> y >> w;
        x--; y--;
        a[x][y] = min(a[x][y],w);
    }
    int aa,bb;
    cin >> aa >> bb;
    aa--; bb--;
    Floyd();
    cout << a[aa][bb];

    return 0;
}
