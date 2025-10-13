#include <bits/stdc++.h>
using namespace std;

int a[10000];
void quicksort(int l, int r){
    int p = a[(l+r)/2];
    int i = l;
    int j = r;
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
        quicksort(l, j);
    }
    if(i<r){
        quicksort(i, r);
    }

}

int main(){
    int n;
    cin >> n;
    quicksort(0, n-1);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    return 0;
}