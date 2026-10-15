// edje list

#include <bits/stdc++.h>
using namespace std;

struct edje{
    int u,v;
}

vector<edje> g;
int n,m,x,y;

int main(){
    cin >> n >> m;
    for(auto &e: g){
        cin >> e.u >> e.v;
    }
    for(auto &e: g){
        cout << e.u << e.v;
    }


    return 0;
}