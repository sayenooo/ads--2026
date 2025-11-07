#include <bits/stdc++.h>
using namespace std;

unordered_set<long long> st;
vector<long long> get_h(string s){
    int n = s.size();
    vector<long long> h(n);

    h[0] = s[0];
    long long p = 31;
    long long p_pow = 31;
    for(int i = 1; i<n; i++){
        h[i] = h[i-1] + s[i]*p_pow;
        p_pow *= p;
        
    }
    return h;
}
vector<long long> get_p(string s){
    int n = s.size();
    vector<long long> p(n);

    p[0] = 1;
    for(int i = 1; i<n; i++){
        p[i] = p[i-1]*31;
    }
    return p;
}
long long func(string s){
    int n = s.size();
    vector<long long> h = get_h(s);
    vector<long long> p = get_p(s);

    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            long long hash = h[j];
            if(i>0){
                hash -= h[i-1];
            }

            st.insert(hash);
        }
        
    }
    return st.size();
}
int main(){
    string s;
    cin >> s;
    cout << func(s);
}
