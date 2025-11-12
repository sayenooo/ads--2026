#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();

    vector<int> pf(n);
    for(int i = 1; i < n; i++){
        int j = pf[i-1];
        while(j > 0 && s[i] != s[j]) j = pf[j-1];
        if(s[i] == s[j]) j++;
        pf[i] = j;
    }

    long long ans = 0;

    // i = length of A (and B)
    for(int i = 1; 2*i < n; i++){
        // check if s[0..i-1] == s[i..2*i-1]
        if(pf[2*i-1] > i) ans++;
    }

    cout << ans;
}
