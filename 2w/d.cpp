#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
    long long n;
    cin >> n;
    map<long long,long long> m;
    long long mx = 0;
    for(int i = 0; i<n; i++){
        long long x;
        cin >> x;
        m[x]++;
        mx = max(mx,m[x]);
    }
    stack<int>q;
    for(auto it:m){
        if(it.second==mx){
            q.push(it.first);
        }
    }
    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }

    return 0;
}