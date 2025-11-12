#include <bits/stdc++.h>
using namespace std;

long long func(string s){
    long long n = s.size();

    vector<long long> pf(n);
    pf[0] = 0;

    for(long long i = 1; i<n; i++){
        long long j = pf[i-1];
        while(j>0 && s[i]!=s[j]){
            j = pf[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        pf[i] = j;
    }
    long long len = pf[n-1];
    return len;
}
// min_length=n+(k−1)⋅(n−pf[n−1])


int main(){
    long long n;
    cin >> n;
    for(long long i = 0; i<n; i++){
        string t;
        long long count;
        cin >> t >> count;
        int pf = func(t);
        long long res = t.size() + (count-1)*(t.size() - pf);
        cout << res << endl;
    }

    return 0;
}
