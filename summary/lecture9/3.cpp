// zet function

#include <bits/stdc++.h>
using namespace std;

vector<int> get_zet(string s) {
    int n = s.size();
    vector<int> z(n);
    z[0] = 0;

    for(int i = 1, l = 0, r = 0; i < n; i++) {
        if(r > i){
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[z[i] + i]){
            z[i]++;
        }
        if(i + z[i] > r){
            l = i; r = i + z[i];
        }
    }

    return z;
}

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> z = get_zet(s);
    int count = 0;

    for(int i = 1; i <= n/2; i++){ 
        if(z[i] >= i){
            count++; 
        }
    }

    cout << count;
    
    return 0;
}