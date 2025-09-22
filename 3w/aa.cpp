#include <bits/stdc++.h>
using namespace std;


pair<int,int> solve(vector<pair<int,pair<int,int>>>v, int num){
    int l = 0;
    int r = v.size()-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(v[mid].first==num){
            return v[mid].second;
        }else if(v[mid].first<num){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return {-1,-1};
}

int main() {
    int x;
    cin >> x;
    queue<int> q;
    for(int i = 0; i<x; i++){
        int y;
        cin >> y;
        q.push(y);
    }
    int n,m;
    cin >> n >> m;
    vector<pair<int,pair<int,int>>>v;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int y;
            cin >> y;
            v.push_back({y,{i,j}});
        }
    }
    sort(v.begin(), v.end());
    while(!q.empty()){
        auto res = solve(v,q.front());
        if(res.first==-1 && res.second==-1){
            cout << -1 << endl;
        }else{
            cout << res.first << " " << res.second << endl;
        }
        q.pop();
    }


    return 0;
}
