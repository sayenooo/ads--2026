#include <bits/stdc++.h>
using namespace std;

int main() {
    float n,m;
    cin >> n >> m;
    vector<float> v(n);
    queue<float>q;
    for(int i = 0; i<n; i++){
        cin >> v[i];
        q.push(v[i]/2);
    }
    float result;
    while(!q.empty()){
        float res = 0;
        for(int i = 0; i<n; i++){
            float x = ceil(v[i]/q.front());
            res+=x;
        }
        if(res<=m){
            result = q.front();
        }
        q.pop();
    }

    cout << result;
    return 0;
}