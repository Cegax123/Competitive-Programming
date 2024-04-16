#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;
const int LOGN = 20;

bool r[maxn];
vector<pair<int, int>> adj[maxn];
ll h[maxn], val[maxn];
int st[maxn], fin[maxn];
int timer = 0;
int up[maxn][LOGN];
int cnt[maxn];

void dfs(int v, int p) {
    st[v] = timer++;

    cnt[v] = r[v];

    if(p != v) cnt[v] += cnt[p];
    
    up[v][0] = p;
    for(int i = 1; i < LOGN; i++)
        up[v][i] = up[up[v][i-1]][i-1];

    if(r[v]) val[v] = 0;

    for(auto [to, w] : adj[v]) if(to != p) {
        h[to] = h[v] + w;
        val[to] = val[v] + w;

        dfs(to, v);
    }

    fin[v] = timer++;
}

bool is_parent(int u, int v) {
    return st[u] <= st[v] and fin[v] <= fin[u];
}

int lca(int u, int v) {
    if(is_parent(u, v)) return u;
    if(is_parent(v, u)) return v;

    for(int i = LOGN-1; i >= 0; i--) {
        if(!is_parent(up[u][i], v))
            u = up[u][i];
    }

    return up[u][0];
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m, q; cin >> n >> m >> q;

        for(int i = 0; i < n; i++) {
            r[i] = 0;
            adj[i].clear();
        }

        for(int i = 0; i < m; i++) {
            int x; cin >> x; x--;
            r[x] = 1;
        }

        for(int i = 0; i < n-1; i++) {
            int u, v, w; cin >> u >> v >> w;
            u--; v--;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        timer = 0;
        dfs(0, 0);

        while(q--) {
            int k; cin >> k;
            vector<int> v;
            for(int i = 0; i < k; i++) {
                int x; cin >> x; x--;
                v.push_back(x);
            }

            sort(v.begin(), v.end(), [](int x, int y) {
                    return val[x] > val[y];
                    });
            
            ll ans = val[v[0]];
            int p = v[0];
            for(int i = 0; i < k; i++) {
                int np = lca(p, v[i]);
                
                if(cnt[np] != cnt[p] or cnt[np] != cnt[v[i]]) break;
                p = np;

                ll curr = max(h[v[0]]-h[p], (i+1 < k ? val[v[i+1]] : 0));
                //cout << curr << endl;
                ans = min(ans, curr);
            }

            cout << ans << "\n";
        }
    }


    return 0;
}
