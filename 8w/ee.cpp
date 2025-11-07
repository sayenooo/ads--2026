#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin, s);

    long long h = 0;
    long long p = 2;
    long long p_pow = 1;

    for(int i = 0; i < s.size(); i++){
        h += (s[i] - 'a') * p_pow;
        cout << h << " ";
        p_pow *= p;
    }
}
