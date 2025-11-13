#include <bits/stdc++.h>
using namespace std;

vector<int> pref_f(string s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    
    string s;
    cin >> s;
    int n = s.size();
    
    vector<int> pf = pref_f(s);
    
    long long count = 0;
    for (int i = 1; i <= (n-1)/2; i++) {
        long long len = 2*i;
        long long p = len - pf[len-1];
        if(i%p==0 && len%i==0){
            count++;
        }
    }
    
    cout << count;
    
    return 0;
}
