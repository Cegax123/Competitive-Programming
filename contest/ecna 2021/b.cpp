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

int a[maxn];
int in[maxn];
vi adj[maxn];
int par[maxn][LOGN];
int val[maxn];
int out[maxn];
int st[maxn], fin[maxn];
int timer= 0;

void dfs(int v, int p) {
    if(v == 0) par[v][0] = 0;
    else par[v][0] = p;

    if(v == 0) val[v] = a[v];
    else val[v] = val[p] + a[v];

    for(int i = 1; i < LOGN; i++) {
        par[v][i] = par[par[v][i-1]][i-1];
    }

    st[v] = timer++;

    for(int to : adj[v]) {
        dfs(to, v);
    }

    fin[v] = timer++;
}

bool is_ancestor(int u, int v) {
    return st[u] <= st[v] and fin[v] <= fin[u];
}

int lca(int u, int v) {
    if(is_ancestor(u, v)) return u;
    if(is_ancestor(v, u)) return v;

    for(int i = LOGN-1; i >= 0; i--) {
        if(!is_ancestor(par[u][i], v)) u = par[u][i];
    }

    return par[u][0];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
	
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);

        in[v]++;
        out[u]++;
    }

    vi s;
    for(int i = 1; i <= n; i++) {
        if(in[i] == 0) adj[0].pb(i);

        if(out[i] == 0) s.pb(i);
    }

    dfs(0, 0);

    //cout << lca(4, 5) << endl;

    int ans = 1e9;

    for(int x : s) {
        for(int y : s) {
            if(x == y) continue;
            ans = min(ans, val[x] + val[y] - val[lca(x, y)]);
        }
    }

    cout << ans << "\n";

    return 0;
}


