#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

vector<int> adj[maxn];
bool vis[maxn], paired[maxn];
vector<pair<pair<int, int>, int>> ans;

void dfs(int v, int p=-1) {
    vis[v] = 1;
    vector<int> notp;

    for(int to : adj[v]) if(to != p and !vis[to]) {
        dfs(to, v);
        if(!paired[to]) notp.push_back(to);
    }

    while((int) notp.size() >= 2) {
        int x = notp.back(); notp.pop_back();
        int y = notp.back(); notp.pop_back();

        ans.push_back({{x, y}, v});
        paired[x] = paired[y] = 1;
    }

    if(!notp.empty()) {
        int x = notp.back();
        ans.push_back({{v, x}, -1});
        paired[v] = paired[x] = 1;
    }
}

int main() {
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < 2 * n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    bool cmp = 1;

    for(int i = 0; i < 2 * n; i++) {
        if(!paired[i]) cmp = 0;
    }

    if(!cmp) cout << "IMPOSSIBLE\n";
    else {
        cout << "POSSIBLE\n";

        for(auto e : ans) {
            cout << e.first.first << " " << e.first.second << " " << e.second << "\n";
        }
    }

    return 0;
}
