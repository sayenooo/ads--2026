#include <bits/stdc++.h>
using namespace std;

bool func(string a, string b){
    return a<b;
}
void merge(vector<string> &s, int l, int r, int m){
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<string> L(n1);
    vector<string> R(n2);
    for(int i = 0; i<n1; i++){
        L[i] = s[l+i];
    }
    for(int i = 0; i<n2; i++){
        R[i] = s[m+1+i];
    }
    int uk1 = 0;
    int uk2 = 0;
    int k = l;
    while(uk1<n1 && uk2<n2){
        if(L[uk1].size() < R[uk2].size()){
            s[k] = L[uk1];
            uk1++;
        }else if(L[uk1].size() > R[uk2].size()){
            s[k] = R[uk2];
            uk2++;
        }else{
            if(func(L[uk1],R[uk2])){
                s[k] = L[uk1];
                uk1++;
            }else{
                s[k] = R[uk2];
                uk2++;
            }
        }
        k++;
    }
    while(uk1<n1){
        s[k] = L[uk1];
        uk1++;
        k++;
    }
    while(uk2<n2){
        s[k] = R[uk2];
        uk2++;
        k++;
    }
}
void mergesort(vector<string> &s, int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergesort(s, l, m);
        mergesort(s, m+1, r);
        merge(s, l, r, m);
    }
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    vector<string>a;

    for(int i = 0; i<n; i++){
        a.clear();
        string ss;
        getline(cin, ss);
        stringstream s(ss);
        string c;
        while(s >> c){
            a.push_back(c);
        }
        mergesort(a, 0, a.size() - 1);
        for(int i = 0; i<a.size(); i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}