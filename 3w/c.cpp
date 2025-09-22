#include <bits/stdc++.h>
using namespace std;

int func(vector<long long> &v, int l1, int r1, int l2, int r2){
    int count = 0;
    for(int i = 0; i<v.size(); i++){
        if((v[i]>=l1 && v[i]<=r1) || (v[i]>=l2 && v[i]<=r2)){
            count++;
        }
    }
    return count;
}

int main() {
    int a,b;
    cin >> a >> b;
    vector<long long> v(a);
    for(int i = 0; i<a; i++){
        cin >> v[i];
    }
    for(int i = 0; i<b; i++){
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int res = func(v,l1,r1,l2,r2);
        cout << res << endl;
    }

    return 0;
    
}
