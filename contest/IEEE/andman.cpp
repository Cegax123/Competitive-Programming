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

const int maxn = 1e5+5;
const int LOGN = 20;
const ll mod = (ll) 1e9 + 7;

int n;
ll w[maxn], val[maxn];
vi adj[maxn];

int sz[maxn];
int p[maxn][LOGN];
ll t[4 * maxn], lazy[4 * maxn];
int st[maxn], fin[maxn];
vector<int> se;
int pos[maxn];
int T;

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = w[se[tl]];
        lazy[v] = 1;
    }
    else {
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);

        t[v] = (t[v * 2] * t[v * 2 + 1]) % mod;
        lazy[v] = 1;
    }
}

void push(int v) {
    t[v * 2] = (t[v * 2] * lazy[v]) % mod;
    lazy[v * 2] = (lazy[v * 2] * lazy[v]) % mod;

    t[v * 2 + 1] = (t[v * 2 + 1] * lazy[v]) % mod;
    lazy[v * 2 + 1] = (lazy[v * 2 + 1] * lazy[v]) % mod;

    lazy[v] = 1;
}

void update(int v, int tl, int tr, int l, int r, ll x) {
    if(tr < l or r < tl) return;
    if(tl == l and r == tr) {
        t[v] = (t[v] * x) % mod;
        lazy[v] = (lazy[v] * x) % mod;
    }
    else {
        push(v);
        int tm = (tl + tr) >> 1;
        update(v * 2, tl, tm, l, min(r, tm), x);
        update(v * 2 + 1, tm + 1, tr, max(tm+1, l), r, x);

        t[v] = (t[v * 2] * t[v * 2+1]) % mod;
    }
}

ll query(int v, int tl, int tr, int pos) {
    if(tl == tr) 
        return t[v];
    else {
        push(v);
        int tm = (tl + tr) >> 1;
        if(pos <= tm) return query(v * 2, tl, tm, pos);
        else return query(v * 2 + 1, tm+1, tr, pos);
    }
}

void dfs(int v, int par) {
    p[v][0] = par;

    for(int i = 1; i < LOGN; i++) 
        p[v][i] = p[p[v][i-1]][i-1];

    w[v] = (w[v] * w[par]) % mod;

    sz[v] = 1;

    st[v] = T++;

    se.pb(v);

    for(int to : adj[v]) {
        if(to == par) continue;
        dfs(to, v);

        sz[v] += sz[to];
    }

    fin[v] = T++;
}

bool is_parent(int u, int v) {
    return st[u] <= st[v] and fin[v] <= fin[u];
}

int lca(int u, int v) {
    if(is_parent(u, v)) return u;
    else if(is_parent(v, u)) return v;

    for(int i = LOGN-1; i >= 0; i--) {
        if(!is_parent(p[u][i], v))
            u = p[u][i];
    }

    return p[u][0];
}


ll ex(ll a, ll b, ll c) {
	ll ans = 1;

	while(b > 0) {
		if(b&1) ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        T = 1;
        cin >> n;

        val[0] = 1;
        w[0] = 1;
        for(int i = 1; i <= n; i++) {
            cin >> w[i];
            val[i] = w[i];
        }

        adj[0].pb(1);
        adj[1].pb(0);

        for(int i = 0; i < n-1; i++) {
            int u, v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }


        dfs(0, 0);

        for(int i = 0; i <= n; i++)
            pos[se[i]] = i;

        build(1, 0, n);

        int q; cin >> q;
        while(q--) {
            int op; cin >> op;
            if(op == 1) {
                int u, v; cin >> u >> v;
                ll x = ex(val[u], mod-2, mod) * v % mod;
                val[u] = v;
                update(1, 0, n, pos[u], pos[u] + sz[u] - 1, x);
            }
            else {
                int u, v; cin >> u >> v;
                int l = lca(u, v);

                ll d = query(1, 0, n, pos[p[l][0]]);
                d = ex(d, mod-2, mod);

                ll e = query(1, 0, n, pos[l]);
                e = ex(e, mod-2, mod);

                ll x = query(1, 0, n, pos[u]);
                ll y = query(1, 0, n, pos[v]);

                x = x * d % mod;
                y = y * e % mod;

                ll ans = x * y % mod;

                cout << ans << "\n";
            }
        }

        se.clear();
        for(int i = 0; i <= n; i++) 
            adj[i].clear();
    }

	
    return 0;
}


