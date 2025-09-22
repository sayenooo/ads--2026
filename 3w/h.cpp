#include <bits/stdc++.h>
using namespace std;

int func(vector<long long>v, int x){
    int block = 1;
    long long iter = 1;
    for(int i = 0; i<v.size(); i++){
        if(x>=iter && x<iter+v[i]){
            return block;
        }
        iter+=v[i];
        block++;
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<long long>v;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int j = 0; j<m; j++){
        int x;
        cin >> x;
        int block = func(v,x);
        cout << block << endl;
    }
    

    return 0;
}