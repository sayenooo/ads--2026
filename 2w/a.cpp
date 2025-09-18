#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>v;
    vector<int>vv;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int k;
    cin >> k;
    for(int i = 0; i<n; i++){
        int x = abs(k-v[i]);
        vv.push_back(x);
    }
    vector<int>sorted = vv;
    sort(sorted.begin(),sorted.end());
    int res;
    for(int i = 0; i<n; i++){
        if(vv[i]==sorted[0]){
            res = i;
            break;
        }
    }
    cout << res;

    return 0;
}