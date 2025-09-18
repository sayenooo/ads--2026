#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    stack<int> q;
    queue<int> s;

    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        vector<int>vv;
        if(q.empty()){
            v.push_back(-1); 
        }
        else{
            if(x>q.top()){
                v.push_back(q.top());
            }else{
                s.push(x);
                if(!s.empty() && s.front()<x){
                    v.push_back(s.front());
                }else{
                    v.push_back(-1);
                }

            }
        }
        q.push(x);
    }

    for(int i: v){
        cout << i << " ";
    }




    return 0;
}