#include <bits/stdc++.h>
using namespace std;

bool func(string s, string t){
    return s.find(t)!=string::npos;
}

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
bool found(string s, string t){
    vector<int> p = get_prefix(t + "#" + s);
    for(int x: p){
        if(x == t.size()){
            return true;
        }
    }
    return false;
}

int main(){
    string s, t;
    cin >> s;
    cin >> t;

    string ss = s;
    int count = 1;

    while(ss.size() < t.size()){
        ss+=s;
        count++;
    }

    if(found(ss,t)){
        cout<<count;
    }else{
        ss+=s;
        count++;
        if(found(ss, t)){
            cout<<count;
        }
        else{
            cout<<-1;
        }
    }

}