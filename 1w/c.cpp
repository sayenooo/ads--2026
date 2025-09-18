#include <bits/stdc++.h>
using namespace std;

string func(string s){
    deque<char> q;
    string ss = "";
    for(char c:s){
        if(c!='#'){
            q.push_back(c);
        }else{
            q.pop_back();
        }
    }
    while(!q.empty()){
        ss+=q.front();
        q.pop_front();
    }

    return ss;
}




int main() {
    string a,b;
    cin >> a >> b;
    if(func(a)==func(b)){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}



    return 0;
}
