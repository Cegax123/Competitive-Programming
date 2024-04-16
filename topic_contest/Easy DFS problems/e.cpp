#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;
vector<int> adj[maxn];

bool vis[maxn];
vector<vector<int>> cycles;
vector<int> curr;

void dfs(int v, int p, int root) {
    curr.push_back(v);
    vis[v] = 1;


    for(int to : adj[v]) if(to != p) {
        if(vis[to]) {
            if(to == root) {
                cycles.push_back(curr);
            }
        }
        else {
            dfs(to, v, root);
        }
    }
    curr.pop_back();
}

int main() {
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < n; i++)
        sort(adj[i].begin(), adj[i].end());

    for(int i = 0; i < n; i++) {
        memset(vis, 0, sizeof(vis));
        dfs(i, -1, i);
        if(!cycles.empty()) break;
    }

    if(cycles.empty()) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        sort(cycles.begin(), cycles.end());

        cout << cycles[0].size() << "\n";
        for(int x : cycles[0]) cout << x+1 << " ";
    }

    return 0;
}
