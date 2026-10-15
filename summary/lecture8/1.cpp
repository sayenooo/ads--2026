// Hashing - хэшированмие

#include <bits/stdc++.h>
using namespace std;

int get_hash(string s){
    int h = 0;
    int p_pow = 1;
    int p = 31;

    for(int i = 0; i<s.size(); i++){
        h += s[i]*p_pow;
        p_pow *= p;
    }
    return h;
}


int main() {
    cout << "hash('abc') = " << get_hash("abc") << endl;
    cout << "hash('hello') = " << get_hash("hello") << endl;
    cout << "hash('world') = " << get_hash("world") << endl;

    return 0;
}