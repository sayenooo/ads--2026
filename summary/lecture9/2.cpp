// Knuth-Moris-Pratt - для нахождения подстроки

#include <bits/stdc++.h>
using namespace std;

vector<int> get_prefix(string s){
    int n = s.size();
    vector<int> p(n);

    p[0] = 0;
    for(int i = 1; i<n; i++){
        int j = p[i-1];
        while(j>0 && s[i]!=s[j]){
            j = p[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        p[i] = j;
    }
    return p;
}
void KMP(string s, string t){
    string ss = s+"#"+t;
    int n = ss.size();
    int m = t.size();

    vector<int> p = get_prefix(ss);
    for(int i = m+1; i<n; i++){
        if(p[i]==m){
            int pos = i-2*m;
            cout << pos << " ";
        }
    }
}
int main(){
    string s, t;
    cin >> s >> t;
    KMP(s,t);

    return 0;
}