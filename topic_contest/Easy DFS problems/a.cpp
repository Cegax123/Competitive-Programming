#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> adj[maxn];

int col[maxn];
bool used[maxn];
int cc = 1;
vector<int> curr;
vector<vector<int>> comp;

void dfs(int v) {
    col[v] = cc;
    used[v] = 1;
    curr.push_back(v);
    for(int to : adj[v]) {
        if(!used[to]) dfs(to);
    }
}

int main() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            curr.clear();
            dfs(i);
            comp.push_back(curr);
        }
    }

    for(auto& v : comp) sort(v.begin(), v.end());
    int k = comp.size();

    vector<int> ord(k);
    iota(ord.begin(), ord.end(), 0);

    sort(ord.begin(), ord.end(), [&](int x, int y) {
            return comp[x][0] < comp[y][0];
            });

    cout << k << "\n";
    for(int i = 0; i < k; i++) {
        cout << comp[ord[i]].size() << " ";
        for(int x : comp[ord[i]]) cout << x+1 << " ";
        cout << "\n";
    }

    return 0;
}
