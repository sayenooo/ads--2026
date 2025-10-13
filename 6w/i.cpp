#include <bits/stdc++.h>
using namespace std;

vector<char> alphabet = {'a','b','c','d','e','f','g','h','i','j','k',
    'l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

char a[26] ;

void quicksort(char c){
    for(int i = 0; i<alphabet.size(); i++){
        if(alphabet[i]==c){
            a[i]++;
        }
    }
}
void qsort(){
    for(int i = 0; i<alphabet.size(); i++){
        int count = 0;
        while(a[i]>count){
            cout<<alphabet[i];
            count++;
        }
    }
}
int main(){
    string s;
    cin >> s;
    for(int i = 0; i<s.size(); i++){
        quicksort(s[i]);
    }
    qsort();

    return 0;
}