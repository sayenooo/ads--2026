#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int maxm = 10000;
int g[maxm][maxm];
int n,m,x,y,w;

void Floyd(){
    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(g[i][j]>g[i][k]+g[k][j]){
                    g[i][j] = g[i][k]+g[k][j];
                }
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            g[i][j] = INF;
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> w;
            g[i][j] = min(g[i][j],w);
        }
    }
    vector<int> a;
    for(int i = 0; i<n; i++){
        cin >> y;
        y--;
        a.push_back(y);
    }
    Floyd();
    for(int i = 0; i<n; i++){
        if(i==0){
            cout << g[a[i]][a[i]] << endl;
        }else{
            cout << g[a[i-1]][a[i]] << endl;
        }
    }


    return 0;
}