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

const int maxn = 1e5 + 5, LOGN = 20;
const int B = 375;
const int INF = 1e9;

int st[maxn], en[maxn], T = 0;
int d[maxn], c[maxn], h[maxn], par[maxn][LOGN];
vi adj[maxn];

int n, q;
int a[maxn];

void dfs(int v, int p = -1) {
    st[v] = T++;
    
    if(p == -1) h[v] = 0;
    else h[v] = h[p] + 1;

    if(p == -1) par[v][0] = v;
    else par[v][0] = p;

    for(int i = 1; i < LOGN; i++) 
        par[v][i] = par[par[v][i-1]][i-1];

    for(int to : adj[v]) {
        if(to == p) continue;
        dfs(to, v);
    }

    en[v] = T++;
}

bool is_parent(int u, int v) {
    return st[u] <= st[v] and en[v] <= en[u];
}

int lca(int u, int v) {
    if(is_parent(u, v))
        return u;

    if(is_parent(v, u))
        return v;

    for(int i = LOGN-1; i >= 0; i--) {
        if(!is_parent(par[u][i], v))
            u = par[u][i];
    }

    return par[u][0];
}

void recalc() {
    queue<int> Q;

    for(int i = 0; i < n; i++) {
        d[i] = INF;
        if(c[i]) {
            Q.push(i);
            d[i] = 0;
        }
    }

    while(!Q.empty()) {
        int u = Q.front(); Q.pop();

        for(int to : adj[u]) {
            if(d[to] != INF) continue;
            d[to] = d[u] + 1;
            Q.push(to);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(0);

    c[0] = 1;
    d[0] = 0;

    vi new_red;

    for(int i = 0; i < q; i++) {
        if(i % B == 0) {
            new_red.clear();
            recalc();
        }

        int op; cin >> op;
        int v; cin >> v;
        v--;

        if(op == 1) {
            c[v] = 1;
            new_red.pb(v);
        }
        else {
            int ans = d[v];

            for(int x : new_red) {
                int p = lca(x, v);
                int curr = h[x] - h[p] + h[v] - h[p];
                ans = min(ans, curr);
            }

            cout << ans << "\n";
        }
    }
	
    return 0;
}


