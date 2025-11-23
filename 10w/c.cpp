#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    vector<int> v;
    int x = b;

    while(x>a){
        v.push_back(x);
        if(x%2==0){
            x = x/2;
        }else{
            x = x + 1;
        }
    }
    while(x<a){
        v.push_back(x);
        x = x + 1;
    }
    cout << v.size() << endl;
    for(int i = v.size()-1; i>=0; i--){
        cout << v[i] << " ";
    }

    


    return 0;
}