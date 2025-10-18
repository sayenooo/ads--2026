#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1];
    int R[n2];
    for(int i = 0; i<n1; i++){
        L[i] = a[l + i];
    }
    for(int i = 0; i<n2; i++){
        R[i] = a[m + 1 + i];
    }
    int k = l;
    int uk1 = 0;
    int uk2 = 0;
    while(uk1<n1 && uk2<n2){
        if(L[uk1]<=R[uk2]){
            a[k] = L[uk1];
            uk1++;
        }else{
            a[k] = R[uk2];
            uk2++;
        }
        k++;
    }
    while(uk1<n1){
        a[k] = L[uk1];
        uk1++;
        k++;
    }
    while(uk2<n2){
        a[k] = R[uk2];
        uk2++;
        k++;
    }
}
void mergesort(vector<int> &a , int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main(){
    int n,m;
    cin >> n;
    vector<int> a;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        a.push_back(x);
        
    }
    cin >> m;
    for(int i = 0; i<m; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    int sz = n + m;
    mergesort(a, 0, sz - 1);
    for(int i = 0; i<sz; i++){
        cout << a[i] << " ";
    }

    return 0;
}