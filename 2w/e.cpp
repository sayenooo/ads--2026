#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    stack<string>ss;
    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        if(!ss.empty() && ss.top()!=s){
            ss.push(s);
        }else{
            if(ss.empty()){
                ss.push(s);
            }
        }
    }

    cout << "All in all: "<< ss.size();
    cout << endl;
    cout << "Students:";
    cout << endl;

    while(!ss.empty()){
        cout << ss.top() << endl;
        ss.pop();
    } 

    return 0;
}