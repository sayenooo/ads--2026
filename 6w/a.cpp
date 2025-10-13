#include <bits/stdc++.h>
using namespace std;

vector<char> alphabet = {'a','e','i','o','u',
'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
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
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        char c;
        cin >> c;
        quicksort(c);
    }
    qsort();

    return 0;
}