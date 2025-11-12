#include <bits/stdc++.h>
using namespace std;

vector<int> get_pf(string s){
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
    string s, t;
    int n;
    cin >> s >> n;
    cin >> t;

    string ss = s+"#"+t;
    vector<int> a = get_pf(ss);
    int count = 0;
    for(int i = 0; i<a.size(); i++){
        if(a[i]==s.size()){
            count++;
        }
    }
    if(count>=n){
        cout << "YES";
    }else{
        cout << "NO";
    }
}