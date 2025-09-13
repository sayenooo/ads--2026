#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;036
    vector<int> v;
    vector<int> s;
    while (t--) {
        int n;
        cin >> n;
        s.push_back(n);
        deque<int> dq;

        for (int j = n; j >= 1; --j) {
            dq.push_front(j);
            for (int k = 0; k < j; ++k) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }

        while(!dq.empty()){
            v.push_back(dq.front());
            dq.pop_front();
        }
    }
    int count = 0;
    for(int i = 0; i<s.size(); ++i){
        for(int j = 0; j<s[i]; ++j){
            cout << v[j+count] << " ";
        }
        count+=s[i];
        cout << endl;
    }
}
