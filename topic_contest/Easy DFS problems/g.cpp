#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

vector<int> adj[maxn];
vector<string> ans[maxn];
bool vis[maxn];
int h[maxn];
int st[maxn], fin[maxn];
int timer = 1;

void dfs(int v, int p) {
    vis[v] = 1;
    if(p == -1) h[v] = 0;
    else h[v] = h[p] + 1;
    st[v] = timer++;

    for(int to : adj[v]) {
        if(vis[to]) {
            if(h[v] == h[to]) ans[v].push_back("cross");
            else if(h[v] < h[to]) ans[v].push_back("forward");
            else ans[v].push_back("back");
        }
        else {
            ans[v].push_back("tree");
            dfs(to, v);
        }
    }
    fin[v] = timer++;
}

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        for(int j = 0; j < k; j++) {
            int v; cin >> v; v--;
            adj[i].push_back(v);
        }
    }

    for(int i = 0; i < n; i++) {
        if(!vis[i]) dfs(i, -1);
    }

    for(int i = 0; i < n; i++) cout << st[i] << " ";
    cout << "\n";
    for(int i = 0; i < n; i++) cout << fin[i] << " ";
    cout << "\n";

    for(int i = 0; i < n; i++) {
        if(ans[i].empty()) continue;
        for(auto s : ans[i]) cout << s << " ";
        cout << "\n";
    }

    return 0;
}
