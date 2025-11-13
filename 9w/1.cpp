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
    
    vector<int> pi = pref_f(s);
    
    long long count = 0;
    for (int i = 1; i <= (n-1)/2; i++) {
        int len = 2*i;
        int period = len - pi[len-1];
        if (len % period == 0 && i % period == 0) {
            count++;
        }
    }
    
    cout << count << "\n";
    
    return 0;
}
