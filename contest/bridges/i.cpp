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

const int maxn = 1005;
const int LOGN = 12;

struct Edge{
    int x, y;
};

int n, m, mod;
int f[maxn][maxn];
vi tin, tout, low;
vector<vi> up;
vector<vii> adj;
vector<bool> isBridge, vis;
vector<Edge> edges;
int timer;

int sum(int a, int b) {
    return (a+b)%mod;
}

void init() {
    for(int i = 1; i <= n; i++) {
        f[i][1] = 1%mod;
        f[1][i] = 1%mod;
    }

    f[1][1] = 0;

    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= n; j++) {
            if(i == j) f[i][j] = 0;
            else f[i][j] = sum(sum(f[i-1][j], f[i][j-1]), f[i-1][j-1]);
        }
    }

    timer = 0;

    tin.clear(); tin.resize(n, -1);
    low.clear(); low.resize(n, -1);
    vis.clear(); vis.resize(n, 0);
    adj.clear(); adj.resize(n);
    isBridge.clear(); isBridge.resize(m, 0);
    edges.clear();
}

void dfs(int v, int p = -1) {
    vis[v] = 1;
    tin[v] = low[v] = timer++;

    for(auto e : adj[v]) {
        int to = e.first, id = e.second;
        if(to == p) continue;
        if(vis[to]) {
            low[v] = min(low[v], tin[to]);
        }
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);

            if(low[to] > tin[v]) {
                isBridge[id] = 1;
            }
        }
    }
}

vi idv;
vector<vii> tree;
int d[maxn][maxn], w[maxn][maxn];
int k;
const int INF = 1e9;

void assign_id(int v, int ind) {
    idv[v] = ind;

    for(auto e : adj[v]) {
        int to = e.first, id = e.second;
        if(isBridge[id] or idv[to] != -1) continue;

        assign_id(to, ind);
    }
}

void build_tree() {
    idv.clear(); idv.resize(n, -1);
    
    k = 0;
    for(int i = 0; i < n; i++) {
        if(idv[i] == -1) {
            assign_id(i, k);
            k++;
        }
    }

    tree.clear(); tree.resize(k);

    for(int i = 0; i < m; i++) {
        int x = edges[i].x, y = edges[i].y;

        if(isBridge[i] and idv[x] != idv[y]) {
            w[idv[x]][idv[y]] = f[x+1][y+1];
            w[idv[y]][idv[x]] = f[x+1][y+1];
            tree[idv[x]].pb({idv[y], f[x+1][y+1]});
            tree[idv[y]].pb({idv[x], f[x+1][y+1]});
        }
    }
}

void dfs2(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;

    for(int i = 1; i <= LOGN; i++)
        up[v][i] = up[up[v][i-1]][i-1];

    for(auto e : tree[v]) {
        int to = e.first;
        if(to == p) continue;
        dfs2(to, v);
    }

    tout[v] = ++timer;
}

bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if(isAncestor(u, v))
        return u;
    if(isAncestor(v, u))
        return v;
    for(int i = LOGN; i >= 0; i--) {
        if(!isAncestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.clear(); tin.resize(k);
    tout.clear(); tout.resize(k);
    timer = 0;
    up.clear(); up.resize(k, vi(LOGN+1));
    dfs2(root, root);

    for(int i = 0; i < k; i++) {
        d[i][i] = INF;

        int tmp = i;
        while(tmp) {
            int p = up[tmp][0];
            d[p][i] = min(d[tmp][i], w[p][tmp]);
            tmp = p;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
    while(t--) {
        cin >> n >> m >> mod;

        init();

        for(int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            x--; y--;

            adj[x].pb({y, i});
            adj[y].pb({x, i});

            edges.pb({x, y});
        }

        dfs(0);
        build_tree();
        preprocess(0);

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(idv[i] == idv[j]) continue;
                int u = idv[i], v = idv[j];
                int p = lca(u, v);

                int poss = f[i+1][j+1]-min(d[p][u], d[p][v]);
                ans = max(ans, poss);
            }
        }

        cout << ans << "\n";
    }
	
	return 0;
}
