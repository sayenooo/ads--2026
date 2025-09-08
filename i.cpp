#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    queue <int> q1;
    queue <int> q2;

    for (int i = 0; i<n; i++){
        if (s[i]=='K'){
            q1.push(i);
        }else{
            q2.push(i);
        }
    }
    while(!q1.empty() && !q2.empty()){
        int i1 = q1.front();
        int i2 = q2.front();
        q1.pop();
        q2.pop();
        if(i1<i2){
            q1.push(i1 + n);
        }else{
            q2.push(i2 + n);
        }
    }

    if (!q1.empty()){
        cout << "KATSURAGI";
    }else{
        cout << "SAKAYANAGI";
    }
   

    return 0;
}
