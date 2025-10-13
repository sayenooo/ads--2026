#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> mp;
    for(int i = 0; i<n; i++){
        int day, month, year;
        char dash1, dash2;
        cin >> day >> dash1 >> month >> dash2 >> year;
        mp.push_back({year, {month, day} });
    }
    sort(mp.begin(), mp.end());
    for(int i = 0; i<n; i++){
        if(mp[i].second.second<=9 && mp[i].second.first>=10){
            cout << 0 << mp[i].second.second << '-' << mp[i].second.first << '-' << mp[i].first << endl;
        }
        if(mp[i].second.first<=9 && mp[i].second.second>=10){
            cout << mp[i].second.second << '-' << 0 << mp[i].second.first << '-' << mp[i].first << endl;
        }

        if(mp[i].second.first<=9 && mp[i].second.second<=9){
            cout << 0 << mp[i].second.second << '-' << 0 << mp[i].second.first << '-' << mp[i].first << endl;
        }

        if(mp[i].second.first>=10 && mp[i].second.second>=10){
            cout << mp[i].second.second << '-' << mp[i].second.first << '-' << mp[i].first << endl;
        }
    }

    return 0;
}