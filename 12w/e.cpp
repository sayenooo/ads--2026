#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int maxm = 10000;
int a[maxm][maxm];
int p[maxm][maxm];
int n,w;

void Floyd(){
    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(a[i][j]>a[i][k]+a[k][j]){
                    a[i][j]=a[i][k]+a[k][j];
                    p[i][j]=p[k][j];
                }
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> w;
            a[i][j] = w;
            if(a[i][j] < 100000){
                p[i][j] = i;
            }
            else{
                p[i][j] = -1;
            }
        }
    }
    Floyd();
    int v = -1;
    for (int i = 0; i < n; i++) {
        if (a[i][i] < 0) {
            v = i;
            break;
        }
    }

    if (v == -1) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    // Восстанавливаем цикл
    int x = v;
    for (int i = 0; i < n; i++)
        x = p[v][x];

    vector<int> cycle;
    int cur = x;

    do {
        cycle.push_back(cur);
        cur = p[v][cur];
    } while (cur != x);

    cycle.push_back(x);

    cout << cycle.size() << endl;
    for (int u : cycle)
        cout << u << " ";
    return 0;
}