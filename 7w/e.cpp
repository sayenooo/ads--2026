#include <bits/stdc++.h>
using namespace std;
int n, m;
bool func(const vector<vector<int>> &a, int l, int r, int mm) {
    for (int i = 0; i < mm; i++) {
        if (a[l][i] < a[r][i]) return true;  
        if (a[l][i] > a[r][i]) return false; 
    }
    return true;
}

void merge(vector<pair<int,int>> &s, int l, int m, int r, const vector<vector<int>> &a, int n, int mm){
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<pair<int,int>>  L(n1);
    vector<pair<int,int>>  R(n2);
    for(int i = 0; i<n1; i++){
        L[i] = s[l + i];
    }
    for(int i = 0; i<n2; i++){
        R[i] = s[m + 1 + i];
    }
    int k = l;
    int uk1 = 0;
    int uk2 = 0;
    while(uk1<n1 && uk2<n2){
        if(L[uk1].first>R[uk2].first){
            s[k] = L[uk1];
            uk1++;
        }else if(L[uk1].first<R[uk2].first){
            s[k] = R[uk2];
            uk2++;
        }else{
            if(func(a, L[uk1].second,R[uk2].second, mm)){
                s[k] = L[uk1];
                uk1++;
            }else{
                s[k] = R[uk2];
                uk2++;
            }
        }
        k++;
    }
    while(uk1<n1){
        s[k] = L[uk1];
        uk1++;
        k++;
    }
    while(uk2<n2){
        s[k] = R[uk2];
        uk2++;
        k++;
    }
}
void mergesort(vector<pair<int,int>> &s , int l, int r, const vector<vector<int>> &a, int n, int mm){
    if(l<r){
        int m = (l+r)/2;
        mergesort(s, l, m, a, n, mm);
        mergesort(s, m + 1, r, a, n, mm);
        merge(s, l, m, r, a, n, mm);
    }
}

int main() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<pair<int,int>> b;

    for (int i = 0; i < n; i++){
        int sumn = 0;
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            sumn+=a[i][j];
        }
        b.push_back({sumn, i});
    }

    mergesort(b, 0, b.size() - 1, a, n, m);

    for (int i = 0; i < n; i++){
        int count = b[i].second;
        for(int j = 0; j < m; j++){
            cout << a[count][j] << " ";
        }
        cout << endl;
    }

    return 0;
}