#include <bits/stdc++.h>
using namespace std;

vector<string> s;
int Count(string str){
    return str.size();
}

void merge(int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    string L[n1];
    string R[n2];
    for(int i = 0; i<n1; i++){
        L[i] = s[l + i];
    }
    for(int i = 0; i<n2; i++){
        R[i] = s[m + 1 + i];
    }
    int k = l;
    int uk1 = 0;
    int uk2 = 0;
    while(uk1<n1 && uk2<n2){
        if(Count(L[uk1])<=Count(R[uk2])){
            s[k] = L[uk1];
            uk1++;
        }else{
            s[k] = R[uk2];
            uk2++;
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
void mergesort(vector<string>s , int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergesort(s, l, m);
        mergesort(s, m + 1, r);
        merge(l, m, r);
    }
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 0; i<n; i++){
        s.clear();
        string line;
        getline(cin, line);
        
        stringstream ss(line);
        string w;
        while(ss >> w){
            s.push_back(w);
        }

        mergesort(s, 0, s.size() - 1);

        for (auto &x : s){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}