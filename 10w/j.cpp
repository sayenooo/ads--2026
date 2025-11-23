*#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> g[MAXN];
int parent[MAXN];      
int children[MAXN];    
bool used[MAXN];

int main() {
    int n, m;
    cin >> n >> m;

    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int bigfam = 0;

    
    for (int start = 0; start < n; start++) {
        if (used[start]) continue;

      
        int root = start;
        queue<int> q;
        q.push(start);
        used[start] = true;

        vector<int> comp; 
        comp.push_back(start);

        while (!q.empty()) {
            int v = q.front(); q.pop();
            root = min(root, v);

            for (int j = 0; j < g[v].size(); j++) {
                int to = g[v][j];
                if (!used[to]) {
                    used[to] = true;
                    q.push(to);
                    comp.push_back(to);
                }
            }
        }

        // 2) Строим дерево BFS от root
        for (int v : comp) {
            used[v] = false;
            children[v] = 0;
        }

        queue<int> qq;
        qq.push(root);
        used[root] = true;
        parent[root] = -1;

        vector<int> order;
        order.push_back(root);

        while (!qq.empty()) {
            int v = qq.front(); qq.pop();

            for (int j = 0; j < g[v].size(); j++) {
                int to = g[v][j];
                if (!used[to]) {
                    used[to] = true;
                    parent[to] = v;
                    children[v]++;
                    qq.push(to);
                    order.push_back(to);
                }
            }
        }

        // 3) Считаем BigFam
        bigfam++; 
        for (int v : order) {
            if (parent[v] == -1) continue; 
            int p = parent[v];
            if (children[v] > children[p]) {
                bigfam++;
            }
        }
    }

    cout << bigfam << endl;
}
