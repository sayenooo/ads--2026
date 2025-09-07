#include <bits/stdc++.h>

using namespace std;

bool isprime(long long n){
    if (n<=1){
        return false;
    }
    for (long long i = 2; i<=sqrt(n); i++){
        if (n%i==0){
            return false;
        }
    }
    return true;

}

int main(){
    long long n;
    cin >> n;

    if (isprime(n)){
        cout << "YES";  
    }else{
        cout << "NO";   
    }

    return 0;
}