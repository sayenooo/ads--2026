#include <bits/stdc++.h>
using namespace std;

vector<int> func(string s){
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
    return pf;
}

int main(){
    string a, b;
    cin >> a >> b;
    string s = a+"#"+b+b;
    vector<int> pf = func(s);

    int maxm = 0;
    for(int i = 0; i<pf.size(); i++){
        maxm = max(maxm, pf[i]);
    }
    int id = 0;
    for(int i = 0; i<pf.size(); i++){
        if(pf[i]==maxm){
            id = i;
            break;
        }
    }
    int len = id - a.size() - b.size();
    if(len>0){
        cout << len;
    }else{
        cout << -1;
    }
    return 0;
}