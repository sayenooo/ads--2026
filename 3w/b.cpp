#include <bits/stdc++.h>
using namespace std;

int main() {
    int x,y;
    cin >> x >> y;
    vector<long long> v(x);
    for(int i = 0; i<x; i++){
        cin >> v[i];
    }
    long long low = *max_element(v.begin(), v.end());
    long long high = accumulate(v.begin(), v.end(), 0LL);
    long long ans = high;
    while(low<=high){
        long long mid = (low+high)/2;
        long long sumn = 0;
        long long block = 0;
        vector<long long>temp;
        for(int i = 0; i<v.size(); i++){
            if(sumn + v[i] > mid){
                block++;
                temp.push_back(sumn);
                sumn = 0;
            }
            sumn+=v[i];
        }
        block++;
        temp.push_back(sumn);
        if(block>y){
            low = mid + 1;
        }else{
            ans = mid;
            high = mid - 1;
        }
    }
    cout << ans;
    
    

    return 0;
}
