#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int l, int r, int m){
    int  n1 = m - l + 1;
    int n2 = r - m;

    int L(n1);
    int R(n2);

    for(int i = 0; i<n1; i++){
        L[i] = v[l + i];
    }
    for(int i = 0; i<n2; i++){
        R[i] = v[i + m + 1];
    }
    int uk1 = 0;
    int uk2 = 0;
    int k = l;
    while(uk1!=0 && uk2!=0){
        if(L[uk1]<=R[uk2]){
            v[k] = L[uk1];
            uk1++;
        }else{
            v[k] = R[uk2];
            uk2++;
        }
        k++;
    }
    while(uk1!=0){
        v[k] = L[uk1];
        uk1++;
        k++;
    }
    while(uk2!=0){
        v[k] = R[uk2];
        uk2++;
        k++;
    } 
}

void mergesort(vector<int> &v , int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergesort(v, l, m);
        mergesort(v, m + 1, r);
        merge(v, l, r, m);
    }
}
int main(){
    vector<int>v;

    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    int m;
    cin >> m;
    for(int i = 0; i<m; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    mergesort(v, 0, v.size()-1);

    for(int i = 0; i<v.size(); i++){
        cout << v[i] << " ";
    }




    return 0;
}