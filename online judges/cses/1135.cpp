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

const int maxn = 2e5+5;

int n;
vector<vector<int>> adj;

const int LOGN = 20;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;
int h[maxn];

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= LOGN; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p) {
            h[u] = h[v]+1;
            dfs(u, v);
        }
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = LOGN; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n+1);
    tout.resize(n+1);
    timer = 0;
    up.assign(n+1, vector<int>(LOGN+1));
    dfs(root, root);
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q; cin >> n >> q;

    adj.resize(n+1);
    
    for(int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    preprocess(1);

    while(q--) {
        int u, v; cin >> u >> v;

        int k = lca(u, v);

        cout << h[u]+h[v]-2*h[k] << "\n";
    }
    
    return 0;
}
