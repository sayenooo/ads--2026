#include <bits/stdc++.h>
using namespace std;

bool get_pf(string ss, string tt){
    string s = ss + "#" + tt;
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
    int len = pf[n-1];
    if(len==ss.size()){
        return true;
    }
    return false;
}
int main(){
    string s;
    cin >> s;
    
    int count = 0;
    for(int i = 1; i<s.size(); i++){
        string ss = s.substr(0, i);
        string tt = s.substr(i, i);
        if(ss.size() + tt.size() < s.size() && get_pf(ss,tt)){
            count++;
        }
    }
    cout << count;

    return 0;
}