#include <bits/stdc++.h>
using namespace std;

string func(string str){
    string s;
    deque<char> q;
    for(char c: str){
        if(c=='#'){
            q.pop_front();
        }
        if (c!='#'){
            q.push_front(c);          
        }
    }
    while(!q.empty()){
        s+=q.front();
        q.pop_front();
    }

    return s;
}


int main() {
    string s1;
    string s2;
    cin >> s1 >> s2;

    if(func(s1)==func(s2)){
        cout << "Yes";
    }else{
        cout << "No";
    }



    return 0;
}
