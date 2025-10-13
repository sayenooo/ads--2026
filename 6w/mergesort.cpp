#include <bits/stdc++.h>
using namespace std;


void part(vector<int>a, int l, int r, int mid){
    int left = mid - l + 1;
    int right = r - (mid+1) + 1;
    
    vector<int> L(left);
    vector<int> R(right);
    for(int i = 0; i<left; i++){
        L[i] = a[i+left];
    }
    for(int i = 0; i<right; i++){
        R[i] = a[i+right];
    }
    int uk1 = 0;
    int uk2 = 0;
    int k = left;

    vector<int>v(k);
    while (L[uk1]<left && R[uk2]<right){
        if(L[uk1]<R[uk2]){
            v[k] = L[uk1];
            uk1++;
        }else{
            v[k] = R[uk2];
            uk2++;
        }
        k++;
    }
    while(uk1<left){
        v[k] = L[uk1];
        k++;
        uk1++;
    }
    while(uk2<right){
        v[k] = R[uk2];
        k++;
        uk2++;
    } 
}

void mergersort(vector<int>a, int l, int r){
    while(l<r){
        int mid = (left+right)/2;
        
        mergesort(a, left, mid);
        mergersort(a, mid+1, right);
    }
    merge(a, left, right, mid);
}

int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    mergesort(a, 0, n-1);
    for(int i = 0; i<n; i++){
        cout << a[i] << " ";
    }

    return 0;
}