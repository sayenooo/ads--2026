#include <bits/stdc++.h>
using namespace std;

const int maxm = 200005;
int p[maxm];
int r[maxm];
vector<int> g[maxm];
bool active[maxm];

int find(int v){
    if(p[v]==v) return v;
    return p[v]=find(p[v]);
}

void uniony(int u, int v){
    u=find(u);
    v=find(v);
    if(u==v) return;
    if(r[u]<r[v]) swap(u,v);
    p[v]=u;
    if(r[u]==r[v]) r[u]++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    for(int i=0;i<n;i++){
        p[i]=i;
        r[i]=0;
        active[i]=false;
    }
    
    vector<int> ans(n);
    int components=0;
    
    for(int v=n-1;v>=0;v--){
        active[v]=true;
        components++;
        
        for(int u:g[v]){
            if(active[u]){
                if(find(v)!=find(u)){
                    uniony(v,u);
                    components--;
                }
            }
        }
        ans[v]=components;
    }
    
    for(int i=1;i<n;i++){
        cout<<ans[i]<<"\n";
    }
    cout << 0 << "\n";
    
    return 0;
}