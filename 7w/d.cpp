#include <bits/stdc++.h>
using namespace std;

bool func(string a, string b){
    return a < b;
}

void merge(vector<pair<double, pair<string, string>>> &v, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<pair<double, pair<string, string>>> L(n1);
    vector<pair<double, pair<string, string>>> R(n2);
    for(int i = 0; i < n1; i++){
        L[i] = v[l + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = v[m + 1 + i];
    }

    int uk1 = 0, uk2 = 0, k = l;
    while(uk1 < n1 && uk2 < n2){
        if(L[uk1].first < R[uk2].first){
            v[k] = L[uk1];
            uk1++;
        }
        else if(L[uk1].first > R[uk2].first){
            v[k] = R[uk2];
            uk2++;
        }
        else if(L[uk1].second.first != R[uk2].second.first){
            if(func(L[uk1].second.first, R[uk2].second.first)){
                v[k] = L[uk1];
                uk1++;
            } else {
                v[k] = R[uk2];
                uk2++;
            }
        }
        else{
            if(func(L[uk1].second.second, R[uk2].second.second)){
                v[k] = L[uk1];
                uk1++;
            } else {
                v[k] = R[uk2];
                uk2++;
            }
        }
        k++;
    }

    while(uk1 < n1){
        v[k] = L[uk1];
        uk1++;
        k++;
    }
    while(uk2 < n2){
        v[k] = R[uk2];
        uk2++;
        k++;
    }
}

void mergesort(vector<pair<double, pair<string, string>>> &v, int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergesort(v, l, m);
        mergesort(v, m + 1, r);
        merge(v, l, m, r);
    }
}

int main(){
    map<string,double> m;
    m["A+"] = 4.00;
    m["A"]  = 3.75;
    m["B+"] = 3.50;
    m["B"]  = 3.00;
    m["C+"] = 2.50;
    m["C"]  = 2.00;
    m["D+"] = 1.50;
    m["D"]  = 1.00;
    m["F"]  = 0.00;

    int n;
    cin >> n;
    vector<pair<double, pair<string, string>>> v;
    for(int i = 0; i < n; i++){
        string fname, lname;
        cin >> lname >> fname;
        int num;
        cin >> num;
        double sum = 0, total = 0;
        for(int j = 0; j < num; j++){
            string mark;
            int credit;
            cin >> mark >> credit;
            sum += m[mark] * credit;
            total += credit;
        }
        double overall = sum / total;
        v.push_back({overall, {lname, fname}});
    }

    mergesort(v, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout << v[i].second.first << " " << v[i].second.second << " "
             << fixed << setprecision(3) << v[i].first << endl;
    }

    return 0;
}
