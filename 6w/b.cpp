#include <bits/stdc++.h>
using namespace std;

void quicksort(vector<int>& a, int l, int r){
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
        quicksort(a, l, j);
    }
    if(i<r){
        quicksort(a, i, r);
    }

}

int main(){
    int n,m;
    cin >> n >> m;
    map<int, int> mp;
    vector<int>a(m);
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    for(int i = 0; i<m; i++){
        cin >> a[i];
    }
    vector<int>b;
    for(int i = 0; i<m; i++){
        while(mp[a[i]]>0){
            b.push_back(a[i]);
            mp[a[i]]--;
            break;
        }
    }
    quicksort(b, 0, b.size() - 1);   
    for(int i = 0; i<b.size(); i++){
        cout << b[i] << " ";
    }

    return 0;
}
