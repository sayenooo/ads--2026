#include <bits/stdc++.h>
using namespace std;

string get_hash(string s){
    long long h = 0;
    long long p = 11;
    long long p_pow = 1;
    long long mod = 1e9 + 7;
    for(int i = 0; i < s.size(); i++){
        h += ((s[i] - 47) * p_pow) % mod;
        h %= mod;
        p_pow = (p_pow * p) % mod;
    }
    return to_string(h);
}

int main() {
    int n;
    cin >> n;
    vector<string> v(2*n);

    for (int i = 0; i < 2*n; i++){
        cin >> v[i];
    }

    int cnt = 0;
    for (int i = 0; i < 2*n; i++) {
        if (cnt == n){
            break;
        }
        string h = get_hash(v[i]);
        if (find(v.begin(), v.end(), h) != v.end()) {
            cout << "Hash of string "<< '"' << v[i] << '"' << " is " << h << endl;
            cnt++;
        }
    }

    return 0;
}
