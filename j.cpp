#include <bits/stdc++.h>
using namespace std;

int main() {
    
    deque <int> dq;
    vector <string> v;

    while(true){
        string result;
        char c;
        int n;

        cin >> c;
        if (c == '!'){
            break;
        }
        else if (c == '+'){
            cin >> n;
            dq.push_front(n);
        }
        else if (c == '-'){
            cin >> n;
            dq.push_back(n);
        }
        else if (c=='*' && dq.size()>=1){
            result = to_string(dq.front() + dq.back());
            if(dq.size()==1){
                dq.pop_back();
            }else{
                dq.pop_back();
                dq.pop_front();
            }
            v.push_back(result);
        }
        else if (dq.empty()){
            v.push_back("error");
        }
    }
    for (int i = 0; i<v.size(); i++){
            cout << v[i] << endl;
    }

    return 0;
}
