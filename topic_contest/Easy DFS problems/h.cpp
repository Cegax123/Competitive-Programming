#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> adj[maxn];
bool vis[maxn];
int cnt = 0;

void dfs(int v) {
    vis[v] = 1;
    cnt++;

    for(int to : adj[v]) if(!vis[to]) {
        dfs(to);
    }
}

int main() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(m != n-1) {
        cout << "NO\n";
        return 0;
    }

    dfs(0);

    if(cnt == n) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
