#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    deque<string>q;
    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        q.push_back(s);
    }
    
    for(int i = 1; i<=n; i++){
        q.push_back(q.front());
        q.pop_front();
        if(i==m){
            break;
        }
    }
    
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop_front();
    }

    return 0;
}