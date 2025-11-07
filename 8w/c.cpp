#include <bits/stdc++.h>
using namespace std;

//hash
int get_hash(string s){
    int h = 0;
    int p = 31;
    int p_pow = 1;
    for(int i = 0; i < s.size(); i++){
        h += s[i] * p_pow;
        p_pow *= p;
    }
    return h;
}

//hash prefixes
vector<int> get_h(string s){
    int n = s.size();
    vector<int> h(n);

    h[0] = s[0];
    int p_pow = 31;
    int p = 31;

    for(int i = 1; i < n; i++){
        h[i] = h[i-1] + s[i] * p_pow;
        p_pow *= p;
    }
    return h;
}

//get powers
vector<int> get_p(string s){
    int n = s.size();
    vector<int> p(n);

    p[0] = 1;
    for(int i = 1; i < n; i++){
        p[i] = p[i-1] * 31;
    }
    return p;
}

//pairs
vector<pair<int,int>> func(string s, string pattern, vector<int> p){
    vector<pair<int,int>> a;

    int n = s.size();
    int m = pattern.size();

    vector<int> h = get_h(s);
    int p_h = get_hash(pattern);

    for(int i = 0; i <= n - m; i++){
        int j = i + m - 1;
        int hash = h[j];
        if(i > 0){
            hash -= h[i-1];
        }
        if(hash == p_h * p[i]){
            a.push_back({i, i+m-1});
        }
    }
    return a;
}

int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;

    vector<int> P = get_p(s);
    set<int> setty;

    for(int i = 0; i < n; i++){
        string ss;
        cin >> ss;
        vector<pair<int,int>> smth = func(s, ss, P);
        for(auto &it: smth){
            for(int j = it.first; j <= it.second; j++){
                setty.insert(j);
            }
        }
    }

    bool ok = true;
    int i = 0;
    for(int x : setty){
        if(x != i){
            ok = false;
            break;
        }
        i++;
    }

    if(ok && setty.size() == s.size()) cout << "YES";
    else cout << "NO";
    return 0;
}
