#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>v;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int k;
    cin >> k;
    int minn = abs(k-v[0]);
    int idx = 0;
    for(int i = 0; i<n; i++){
        int x = abs(k-v[i]);
        if(x<minn){
            minn=x;
            idx=i;
        }
    }
    cout << idx << " ";
    return 0;
}