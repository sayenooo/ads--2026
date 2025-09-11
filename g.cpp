#include <bits/stdc++.h>
using namespace std;

bool isprime(long long nn){
    if (nn<=1){
        return false;
    }
    for (long long i = 2; i<=sqrt(nn); i++){
        if (nn%i==0){
            return false;
        }
    }
    return true;

}

int prime(int n) {
    vector<int> v;

    int idx = 0;
    int id = 0;

    for (int i = 2; i <= 20000; i++) {
        if(isprime(i)){
            idx++;

        }
        bool aa = false;
        if(isprime(i) && isprime(idx)){
            aa = true;
        }
        if (aa) {
            id+=1;
            v.push_back(i);
        }
    }

    return v[n-1];
}

int main() {
    int n;
    cin >> n;
    cout << prime(n);
}
