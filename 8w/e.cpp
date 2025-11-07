#include <bits/stdc++.h>
using namespace std;

string get_h(vector<long long> a){
    string s = "";
    long long  p = 2;
    long long  p_pow = 1;

    for(int i = 0; i<a.size(); i++){
        long long cur;
        if(i==0){
            cur = a[0];
        }else{
            cur = (a[i]-a[i-1])/p_pow;
        }
        char c = char(cur+97);
        s += c;
        p_pow *= p;

    }
    return s;
}

int main(){
    int n;
    cin >> n;
    vector<long long>a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    cout << get_h(a);
    return 0;
}