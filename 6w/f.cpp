#include <bits/stdc++.h>
using namespace std;

bool func(string s1, string s2){
    return s1 < s2;
}
bool func1(string s1, string s2){
    return s1 > s2;
}

void quicksort(vector<pair<double, pair<string,string>>> &a, int l, int r){
    int i = l;
    int j = r;
    double p = a[(i+j)/2].first;
    string p1 = a[(i+j)/2].second.first;
    string p2 = a[(i+j)/2].second.second;
    while(i <= j){
        while(a[i].first < p || (a[i].first == p && func(a[i].second.first , p1)) || (a[i].first == p && a[i].second.first == p1 && func(a[i].second.second , p2))) i++;
        while(a[j].first > p || (a[j].first == p && func1(a[j].second.first , p1)) || (a[j].first == p && a[j].second.first == p1 && func1(a[j].second.second , p2))) j--;
        if(i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(l < j) quicksort(a, l, j);
    if(i < r) quicksort(a, i, r);
}

int main() {
    int n;
    cin >> n;
    vector<pair<double, pair<string,string>>> mp;
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

    for(int i = 0; i < n; i++) {
        string fname, lname;
        int num;
        cin >> fname >> lname >> num;

        double upper = 0, lower = 0;
        for(int j = 0; j < num; j++) {
            string mark;
            int credit;
            cin >> mark >> credit;
            upper += m[mark] * credit;
            lower += credit;
        }

        double gpa = upper / lower;
        mp.push_back({gpa, {fname, lname}});
    }

    quicksort(mp, 0, mp.size() - 1);

    for (auto &it : mp) {
        cout << it.second.first << " " << it.second.second << " "
             << fixed << setprecision(3) << it.first << endl;
    }

    return 0;
}
