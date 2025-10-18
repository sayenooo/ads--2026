#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &s, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1];
    int R[n2];
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
        if(L[uk1]<=R[uk2]){
            s[k] = L[uk1];
            uk1++;
        }else{
            s[k] = R[uk2];
            uk2++;
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
void mergesort(vector<int> &s , int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergesort(s, l, m);
        mergesort(s, m + 1, r);
        merge(s, l, m, r);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    mergesort(a, 0, n - 1);
    mergesort(b, 0, m - 1);

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            i++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }

    return 0;
}