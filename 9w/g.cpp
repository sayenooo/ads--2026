#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pf(n);
    pf[0] = 0;
    for(int i = 1; i<n; i++){
        int j = pf[i-1];
        while(j>0 && s[i]!=s[j]){
            j = pf[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        pf[i] = j;
    }
    int m = pf[n-1];
    
    cout << n - m;

    return 0;
}