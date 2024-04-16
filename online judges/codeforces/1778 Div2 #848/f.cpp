#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;

const int maxn = 3e5 + 5;

vi tree[maxn], imp;
vii adj[maxn];
int g[maxn], comp[maxn], child[maxn];
bool vis[maxn];
int ind = 0;

void dfs_tree(int u, int p = -1) {
    child[u] = 0;
    if(u == 0) child[u] = 1;

    for(int to : tree[u]) {
        if(to == p) continue;
        dfs_tree(to, u);
        child[u]++;
    }

    if(child[u] % 2 == 0) 
        imp.pb(u);

}

void dfs(int u) {
    vis[u] = true;
    comp[u] = ind;
    for(auto e : adj[u]) {
        int to = e.first, w = e.second;
        if(vis[to]) continue;
        
        g[to] = g[u] ^ w;
        dfs(to);
    }
}

void expand(int u) {
    vis[u] = 1;
    for(auto e : adj[u]) {
        int to = e.first, w = e.second;
        if(vis[to]) continue;
        g[to] = g[u] ^ w;
        expand(to);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q; cin >> n >> q;

    vii edges;

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;

        tree[u].pb(v);
        tree[v].pb(u);

        edges.pb({u, v});
    }

    dfs_tree(0);

    while(q--) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;

        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            g[i] = 0;
            dfs(i);
            ind++;
        }
    }
	
    bool cmp = 1;

    for(int i = 0; i < n; i++) {
        for(auto e : adj[i]) {
            int to = e.first, w = e.second;
            if(w != (g[i] ^ g[to])) {
                cmp = 0;
            }
        }
    }

    if(!cmp) {
        cout << "No\n";
        return 0;
    }

    vi cc[ind];
    int total = 0;

    for(int x : imp) {
        cc[comp[x]].pb(x);
        
        total ^= g[x];
    }

    memset(vis, 0, sizeof(vis));

    bool found = false;

    for(int i = 0; i < ind; i++) {
        //cout << i << ": ";

        //for(int to : cc[i]) cout << to << " ";
        //cout << endl;

        if(cc[i].size() % 2 == 1 and !found) {
            int curr = total ^ g[cc[i][0]];

            g[cc[i][0]] = curr;
            expand(cc[i][0]);

            found = true;
        }
    }

    cout << "Yes\n";

    for(auto e : edges) {
        cout << (g[e.first] ^ g[e.second]) << " ";
    }

    return 0;
}


