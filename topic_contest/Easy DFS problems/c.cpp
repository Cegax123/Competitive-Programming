#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> adj[maxn];

bool vis[maxn];
int p[maxn];

void dfs(int v) {
    vis[v] = 1;
    for(int to : adj[v]) {
        if(vis[to]) continue;

        p[to] = v;
        dfs(to);
    }
}

int main() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    int s, e; cin >> s >> e; s--; e--;

    for(int i = 0; i < n; i++)
        sort(adj[i].begin(), adj[i].end());

    dfs(s);

    if(!vis[e]) {
        cout << "no solution\n";
        return 0;
    }

    vector<int> ans;

    while(!(e == s)) {

        ans.push_back(e);
        e = p[e];
    }

    ans.push_back(s);
    reverse(ans.begin(), ans.end());

    for(int x : ans) {
        cout << x+1 << " ";
    }

    return 0;
}
