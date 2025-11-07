#include <bits/stdc++.h>
using namespace std;

vector<pair<long long,pair<int,int>>> st; //hash -> pos,len
vector<long long> get_h(string s){
    int n = s.size();
    vector<long long> h(n);

    h[0] = s[0];
    long long p = 31;
    long long p_pow = 31;
    for(int i = 1; i<n; i++){
        h[i] = h[i-1] + s[i]*p_pow;
        p_pow *= p;
        
    }
    return h;
}
vector<long long> get_p(string s){
    int n = s.size();
    vector<long long> p(n);

    p[0] = 1;
    for(int i = 1; i<n; i++){
        p[i] = p[i-1]*31;
    }
    return p;
}
void func(string s){
    int n = s.size();
    vector<long long> h = get_h(s);
    vector<long long> p = get_p(s);

    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            long long hash = h[j];
            if(i>0){
                hash -= h[i-1];
            }

            st.push_back({hash, {i, j-i+1}});
        }
        
    }
}
int main(){
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), [](const string &aa, const string &bb){
        return aa.size() < bb.size();
    });
    func(a[0]);

    vector<string> subs;
    for(int j = 0; j<st.size(); j++){
        long long hash = st[j].first;
        int pos = st[j].second.first;
        int len = st[j].second.second;
        string s = a[0].substr(pos, len);

        bool ok = true;
        for(int i = 0; i<a.size(); i++){
            if(a[i].find(s)==string::npos){
                ok = false;
                break;
            }
        }
        if(ok){
            subs.push_back(s);
        }
    }
    sort(subs.begin(), subs.end(), [](const string &aa, const string &bb){
        return aa.size() > bb.size();
    });
    cout << subs[0];
}
