#include <bits/stdc++.h>
using namespace std;

//hash
int get_hash(string s){
    int h = 0;
    int p = 31;
    int p_pow = 1;
    for(int i = 0; i<s.size(); i++){
        h += s[i]*p_pow;
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

    for(int i = 1; i<n; i++){
        h[i] = h[i-1] + s[i]*p_pow;
        p_pow *= p;
    }
    return h;
}

//solution
vector<int> get_smth(string s, string t){
    vector<int> a;
    int n = s.size();
    int m = t.size();

    vector<int> p(n);
    p[0] = 1;
    for(int i = 1; i<n; i++){
        p[i] = p[i-1]*31;
    }
    int p_h = get_hash(t);
    vector<int> h = get_h(s);
    for(int i = 0; i<n-m+1; i++){
        int j = i+m-1;
        int hash = h[j];
        if(i>0){
            hash -= h[i-1];
        }
        if(hash == p_h*p[i]){
            a.push_back(i);
        }
    }
    return a;
}

int main(){
    string s1,s2,t;
    cin >> s1 >> s2 >> t;

    vector<int> p1 = get_smth(s1, t);
    vector<int> p2 = get_smth(s2, t);

    int count, uk1, uk2;
    uk1 = 0;
    uk2 = 0;
    count = 0;
    while(uk1<p1.size() && uk2<p2.size()){
        if(p1[uk1]==p2[uk2]){
            count++;
            uk1++;
            uk2++;
        }else if(p1[uk1]>p2[uk2]){
            uk2++;
        }else{
            uk1++;
        }
    }

    cout << count;



    return 0;
}