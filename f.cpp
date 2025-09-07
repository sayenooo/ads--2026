#include <bits/stdc++.h>

using namespace std;

int prime(int n){
    int theprime;
    for(int i = 2; i<=n*n; i++){
        for(int j = 2; j<i; j++){
            if(i%j==0){
                break;
            }else{
                theprime = i;
            }
        }
    }

}

int main(){
    int n;
    cin >> n;




    return 0;
}