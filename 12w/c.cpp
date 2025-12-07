#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int maxm = 1000;
int a[maxm][maxm];
int b[maxm][maxm];
int n,m,x,y;

void Floyd1(){
    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(a[i][j]>a[i][k]+a[j][k]){
                    a[i][j] = a[i][k]+a[k][j];
                }
            }
        }
    }
}
void Floyd2(){
    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(b[i][j]>b[i][k]+b[j][k]){
                    b[i][j] = b[i][k]+b[k][j];
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            a[i][j] = INF;
            b[i][j] = INF;
        }
    }
    for(int i = 0; i<m; i++){
        cin >> x >> y;
        x--; y--;
        a[x][y] = 1;
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(a[i][j]!=1){
                b[i][j] = 1;
            }
        }
    }
    Floyd1();
    Floyd2();
    int ans = max(a[0][n-1],b[0][n-1]);
    if(ans==INF){
        cout << -1;
    }else{
        cout << ans;
    }

    return 0;
}