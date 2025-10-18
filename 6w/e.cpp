#include <bits/stdc++.h>
using namespace std;


void quicksort(vector<int> &a, int l, int r){
    int i = l;
    int j = r;
    int p = a[(l+r)/2];
    while(i<j){
        while(a[i]>p){
            i++;
        }
        while(a[j]<p){
            j--;
        }
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(l<j){
        quicksort(a, l, j);
    }
    if(i<r){
        quicksort(a, i, r);
    }

}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> a[i][j];
        }
    }
    vector<int>b;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            b.push_back(a[j][i]);
        }
        quicksort(b, 0 , b.size() - 1);
        for(int j = 0; j<n; j++){
            a[j][i] = b[j];
        }
        b.clear();
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}