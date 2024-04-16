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

const int maxn = 1e5 + 5;
int n, m, q;

vi adj[maxn];
int link[maxn];
int h[maxn];
int par[maxn];
bool used[maxn];
int id[maxn];
int K = 1;

bool dfs(int v, int p) {
    if(v == 0) h[v] = 0;
    else h[v] = h[p] + 1;

    par[v] = p;
    used[v] = 1;

    bool to_parent = 0;
    int poss_p = p;

    for(int to : adj[v]) {
        if(to == p) continue;

        if(!used[to]) {
            if(dfs(to, v)) to_parent = 1;
        }
        else {
            if(h[to] < h[poss_p]) poss_p = to;
        }
    }

    if(poss_p != p) link[v] = poss_p;
    else if(to_parent) link[v] = poss_p;

    if(id[v] == 0 and link[v] != -1) {
        int tmp = v;
        while(tmp != link[v]) {
            id[tmp] = K;
            tmp = par[tmp];
        }

        K++;
    }

    if(link[v] == -1 or link[v] == p) return false;
    return true;
}

const int LOGN = 20;

vi tree[maxn];
int up[maxn][LOGN];
int st[maxn], fin[maxn];
int T = 0;

void dfs2(int v, int p) {
    if(v == 0) h[v] = 0;
    else h[v] = h[p] + 1;

    up[v][0] = p;

    for(int i = 1; i < LOGN; i++)
        up[v][i] = up[up[v][i-1]][i-1];

    st[v] = T++;

    for(int to : tree[v]) {
        if(to == p) continue;
        dfs2(to, v);
    }

    fin[v] = T++;
}

bool is_ancestor(int u, int v) {
    return st[u] <= st[v] and fin[v] <= fin[u];
}

int lca(int u, int v) {
    if(is_ancestor(u, v)) return u;
    if(is_ancestor(v, u)) return v;

    for(int i = LOGN-1; i >= 0; i--) {
        if(!is_ancestor(up[u][i], v))
            u = up[u][i];
    }

    return up[u][0];
}

int up_k(int u, int k) {
    for(int i = LOGN-1; i >= 0; i--) {
        if((k>>i)&1) u = up[u][i];
    }
    return u;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(link, -1, sizeof(link));


    cin >> n >> m >> q;
    
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(0, 0);

    for(int i = 1; i < n; i++) {
        int x = (link[i] == -1 ? par[i] : link[i]);

        tree[x].pb(i);
    }

    dfs2(0, 0);

    while(q--) {
        int u, v; cin >> u >> v;
        u--; v--;

        if(h[u] > h[v]) swap(u, v);

        if(is_ancestor(u, v)) {
            cout << h[v] - h[u] << "\n";
            continue;
        }

        int pa = lca(u, v);
        int ans = h[u] + h[v] - 2 * h[pa];

        int pu = up_k(u, h[u]-h[pa]-1);
        int pv = up_k(v, h[v]-h[pa]-1);


        if(id[pu] and id[pu] == id[pv]) ans--;

        cout << ans << "\n";
    }

    return 0;
}


