#include <bits/stdc++.h>
using namespace std;

void quicksort(vector<int> &a, int l, int r){
    int i = l;
    int j = r;
    int p = a[(i+j)/2];
    while(i<j){
        while(a[i]<p){
            i++;
        }
        while(a[j]>p){
            j--;
        }
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(l<j){
        quicksort(a,l,j);
    }
    if(i<r){
        quicksort(a,i,r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    quicksort(a, 0, n-1);
    int mn = abs(a[a.size() - 1]);
    for(int i = 1; i < n; i++){
        mn = min(mn, abs(a[i] - a[i-1]));
    }
    
    for(int i = 1; i < n; i++){
        if(abs(a[i] - a[i-1]) == mn){
            cout << a[i-1] << ' ' << a[i] << ' ';
        }
    }
    
    return 0;
}