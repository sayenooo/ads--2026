// Prefix function - быстрый поиск подстроки

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

int main(){
    string s;
    cin >> s;
    vector<int> p = get_prefix(s);
    for(int i = 0; i<p.size(); i++){
        cout << p[i] << " ";
    }

    return 0;
}