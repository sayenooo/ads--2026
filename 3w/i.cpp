#include <bits/stdc++.h>
using namespace std;

bool func(vector<long long>v, int x){
    long long l = 0;
    long long r = v.size()-1;
    while(l<=r){
        long long mid = (l+r)/2;
        if(v[mid]==x){
            return true;
        }else if(v[mid]>x){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return false;

}

int main(){
    int n;
    cin >> n;
    vector<long long>v(n);
    for(int i = 0; i<n; i++){
        cin >> v[i];
    }
    int m;
    cin >> m;
    if(func(v,m)){
        cout << "Yes";
    }else{
        cout << "No";
    }


    return 0;
}