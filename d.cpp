#include <bits/stdc++.h>
using namespace std;

bool func(string s){
    deque<char> q;
    for(char c:s){
        if(!q.empty() && q.back()==c){
            q.pop_back();
        }
        else{
            q.push_back(c);
        }
    }

    if(!q.empty()){
        return false;
    }
    else{
        return true;
    }
}




int main() {
    string a;
    cin >> a;
    if(func(a)){
        cout << "Yes";
    }else{
        cout << "No";
    }

    return 0;
}

