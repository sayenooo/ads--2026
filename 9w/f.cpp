#include <bits/stdc++.h>
using namespace std;

vector<int> a;
void get_pf(string s, string t){
    string pattern = t + "#" + s;
    int n = pattern.size();
    int m  = t.size();

    vector<int> pf(n);
    pf[0] = 0;

    for(int i = 1; i<n; i++){
        int j = pf[i-1];
        while(j>0 && pattern[i]!=pattern[j]){
            j = pf[j-1];
        }
        if(pattern[i]==pattern[j]){
            j++;
        }
        pf[i] = j;
    }
    for(int i = t.size()+1; i<n; i++){
        if(pf[i]==m){
            a.push_back(i-m+1-m);
        }
    }
}
int main(){
    string s, t;
    cin >> s;
    cin >> t;
    get_pf(s, t);
    cout << a.size() << endl;
    for(int i = 0; i<a.size(); i++){
        cout << a[i] << " ";
    }
    return 0;
}