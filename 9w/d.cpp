#include <bits/stdc++.h>
using namespace std;

string lower(string s){
    string ss = "";
    for(char c: s){
        ss+=tolower(c);
    }
    return ss;
}
vector<pair<int, string>> a;
int max_len = 0;
void func(string s, string t){
    string ss = lower(t) + "#" + lower(s);
    int n = ss.size();

    vector<int> pf(n);
    pf[0] = 0;

    for(int i = 1; i<n; i++){
        int j = pf[i-1];
        while(j>0 && ss[i]!=ss[j]){
            j = pf[j-1];
        }
        if(ss[i]==ss[j]){
            j++;
        }
        pf[i] = j;
    }
    int len = pf[n-1];
    if(len>0){
        max_len = max(max_len, len);
        a.push_back({len, t});
    }
}
int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        string t;
        cin >> t;
        func(s, t);
    }
    vector<string> cities;
    for(auto& x: a){
        if(x.first==max_len){
            cities.push_back(x.second);
        }
    }
    cout << cities.size() << endl;
    for(int i = 0; i<cities.size(); i++){
        cout << cities[i] << endl;
    }

    return 0;
}