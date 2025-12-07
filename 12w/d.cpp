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
                a[i][j] = min(a[i][j], max(a[i][k], a[k][j]));
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            a[i][j] = INF;
        }
    }
    vector<pair<int,int>> g(n);
    for(int i = 0; i<n; i++){
        cin >> g[i].first >> g[i].second;
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            w = abs((g[i].first-g[j].first) + (g[i].second-g[j].second));
            a[i][j] = min(a[i][j],w);
        }
    }
    Floyd();
    cout << a[0][n-1];

    return 0;
}