#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string,string> mp;
    
    for(int i = 0; i<n; i++){
        string oold, nnew;
        cin >> oold >> nnew;
        mp[oold] = nnew;
        bool ok = false;
        for(auto it: mp){
            if(it.second == oold){
                mp.erase(nnew);
                mp.erase(oold);
                mp[it.first] = nnew;
            }
        }
    }
    cout << mp.size() << endl;
    for(auto it: mp){
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}