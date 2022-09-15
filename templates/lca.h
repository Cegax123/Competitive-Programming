
const int maxn = 1e5+5;
const int LOGN = 20;

vi adj[maxn];
int timer = 0; 
int tin[maxn], tout[maxn];
int up[maxn][LOGN+1];

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;

    for(int i = 1; i <= LOGN; i++) 
        up[v][i] = up[up[v][i-1]][i-1];

    for(int to : adj[v]) {
        if(to == p) continue;

        dfs(to, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
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
