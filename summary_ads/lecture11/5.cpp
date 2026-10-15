// DFS - topological sort

#include <bits/stdc++.h>
using namespace std;

const int maxm = 1000;
vector<int> g[maxm];
int used[maxm];
stack<int> st;
int n,m,x,y;

void DFS(int v){
    used[v] = 1;
    for(int i = 0; i<g[v].size(); i++){
        int u = g[v][i];
        if(used[u]==0){
            DFS(u);
        }
    }
    st.push(v);
}

void sorting(){
    for(int i = 0; i<n; i++){
        used[i] = 0; 
    }
    for(int i = 0; i<n; i++){
        if(used[i]==0){
            DFS(i);
        }
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
    }
    sorting();

    return 0;
}