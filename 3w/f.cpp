#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin >> v[i];
    }
    int m;
    cin >> m;
    vector<int> w(m);
    for(int i = 0; i<m; i++){
        cin >> w[i];
    }
    for(int i = 0; i<m; i++){
        int count = 0;
        int sumn = 0;
        for(int j = 0; j<n; j++){
            if(w[i]>=v[j]){
                count++;
                sumn+=v[j];
            }
        }
        cout << count << " " << sumn << endl;
    }



    return 0;
}
