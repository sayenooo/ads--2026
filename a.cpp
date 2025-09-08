#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,t1;
    cin >> t;
    t1 = t;
    vector<int> v;
    vector<int> nums;
    deque<int> dq;

    while(t--){
        int n;
        cin >> n;
        nums.push_back(n);

        for (int i = n; i>0; i--){
            dq.push_back(i);
            for (int j = 0; j<=i; j++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        while(!dq.empty()){
            v.push_back(dq.front());
            dq.pop_front();
        }

        }
        

    int j = 0;
    int aa = 0;
    while (t1--) {
        int n = nums[aa];
        for (int i = 0; i < n; i++) {
            cout << v[j + i] << " "; 
        }
        j += n;
        cout << endl;
        aa++;
    }

    return 0;
}
