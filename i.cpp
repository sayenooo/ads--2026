#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int>dq;
    vector<string>v;

    while(true){
        string result;
        char c;
        cin >> c;
        if (c=='!'){
            break;
        }

        int n;
        if (c=='+'){
            cin >> n;
            dq.push_front(n);
        }
        if (c=='-'){
            cin >> n;
            dq.push_back(n);
        }

        if (c=='*' && dq.size()>=1) {
            result = to_string(dq.front() + dq.back());
            if (dq.size()==1) {
                dq.pop_front();
            }
            else{
                dq.pop_front();
                dq.pop_back();
            }
            v.push_back(result);
        }
        else if (dq.empty()){
            v.push_back("error");
        }
        
        


    }

    for (int i = 0; i<v.size(); i++){
        cout << v[i] << endl;
    }