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
    for(int i = 0; i<m; i++){
        int x;
        cin >> x;
        int count = 0;
        int sumn = 0;
        for(int j = 0; j<n; j++){
            if(x>=v[j]){
                count++;
                sumn+=v[j];
            }
        }

        cout << count << " " << sumn << endl;

    }



    return 0;
}