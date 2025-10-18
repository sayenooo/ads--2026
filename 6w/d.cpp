#include <bits/stdc++.h>
using namespace std;

void quicksort(vector<pair<int, pair<int, int>>> &a, int l, int r){
    int i = l;
    int j = r;
    int p = a[(i+j)/2].first;
    int p1 = a[(i+j)/2].second.first;
    int p2 = a[(i+j)/2].second.second;
    while(i<j){
        while(((a[i].first<p) || (a[i].first==p && a[i].second.first<p1) || (a[i].first==p && a[i].second.first==p1 && a[i].second.second<p2))){
            i++;
        }
        while(((a[j].first>p) || (a[j].first==p && a[j].second.first>p1) || (a[j].first==p && a[j].second.first==p1 && a[j].second.second>p2))){
            j--;
        }
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(l<j){
        quicksort(a,l,j);
    }
    if(i<r){
        quicksort(a,i,r);
    }
}



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
    quicksort(mp, 0, n - 1);
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