#include <bits/stdc++.h>
using namespace std;

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

    sort(mp.begin(), mp.end());

    for (auto it : mp) {
        cout << it.second.first << " " << it.second.second << " "
             << fixed << setprecision(3) << it.first << endl;
    }

    return 0;
}
