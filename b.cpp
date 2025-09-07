#include <bits/stdc++.h>
using namespace std;

int main(){
   int n;
   cin >> n;

   vector<int>v(n);
   stack<int>s;
   for(int i = 0; i<n; i++){
    cin >> v[i];
    s.push(v[i]);
    if(s.empty()){
        s.push(-1);
    }else{
        s.push()
    }

   }

    for(int i = 0; i<n; i++){
    cout << v[i] << "";
   }

    return 0;
}