// Rabin-Karp Algorithm - поис подстроки

#include <bits/stdc++.h>
using namespace std;

//hash
int get_hash(string s){
    int h = 0;
    int p = 31;
    int p_pow = 1;
    for(int i = 0; i<s.size();  i++){
        h += s[i]*p_pow;
        p_pow *= p;
    }
    return h;
}

//prefixes
vector<int> get_h(string s){
    int n = s.size();
    vector<int> h(n);

    h[0] = s[0];
    int p = 31;
    int p_pow = 31;

    for(int i = 1; i<n; i++){
        h[i] = h[i-1] + s[i]*p_pow;
        p_pow *= p;
    }
    return h;
}

//powers
vector<int> get_p(string s){
    int n = s.size();
    vector<int> p(n);

    p[0] = 1;
    for(int i = 1; i<n; i++){
        p[i] = p[i-1]*31;
    }
    return p;
}

// RabinKarp
void RabinKarp(string pattern, string tt){
    vector<int> a;

    int n = pattern.size();
    int m = tt.size();

    int p_h = get_hash(tt);

    vector<int> h = get_h(pattern);
    vector<int> p = get_p(pattern);

    for(int i = 0; i<n-m+1; i++){
        int j = i+m-1;
        int hash = h[j];
        if(i>0){
            hash -= h[i-1];
        }
        if(hash == p_h*p[i]){
            cout << i << " ";
        }
    }
}

int main(){
    string text, pattern;
    cin >> text >> pattern;

    RabinKarp(text, pattern);

    return 0;
}
