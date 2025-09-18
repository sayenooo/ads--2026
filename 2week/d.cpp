#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
    long long n;
    cin >> n;
    map<long long,long long> m;
    for(int i = 0; i<n; i++){
        long long x;
        cin >> x;
        m[x]++;
    }
    deque<int>q;
    for(auto it: m){
       if (q.empty() || it.second > q.front()) {
        q.clear();    
        q.push_back(it.second);
       } else if (it.second == q.front()) {
        q.push_back(it.second);  
       }
    }
    vector<int>v;
    for(auto it: m){
        if(q.front()==it.second){
            v.push_back(it.first);
        }
    }
    reverse(v.begin(),v.end());
    for(int i = 0; i<v.size(); i++){
        cout << v[i] << " ";
    }

    



    return 0;
}