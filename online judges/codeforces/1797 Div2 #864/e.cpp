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

const int maxk = 5e6 +  10, maxn = 1e5 + 5;
const int LOGN = 6;

vi primes, adj[maxk];
bool is_composite[maxk];
int phi[maxk];
int par[maxk][LOGN], h[maxk];

void sieve() {
    phi[1] = 1;
    for(int i = 2; i < maxk; i++) {
        if(!is_composite[i]) {
            primes.pb(i);
            phi[i] = i-1;
        }
        for(int j = 0; j < (int) primes.size() && i * primes[j] < maxk; j++) {
            is_composite[i * primes[j]] = 1;

            if(i % primes[j] == 0) {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            else {
                phi[i * primes[j]] = phi[i] * phi[primes[j]];
            }
        }
    }
}

void build_tree() {
    for(int i = 2; i < maxk; i++) {
        adj[phi[i]].pb(i);
    }
}

void dfs(int v, int p=-1) {
    if(p == -1) {
        par[v][0] = v;
        h[v] = 0;
    }
    else {
        par[v][0] = p;
        h[v] = h[p] + 1;
    }

    for(int i = 1; i < LOGN; i++)
        par[v][i] = par[par[v][i-1]][i-1];

    for(int to : adj[v]) {
        if(to == p) continue;
        dfs(to, v);
    }
}

int lca(int u, int v) {
    if(u == -1) return v;
    if(v == -1) return u;
    if(h[u] > h[v]) swap(u, v);
    
    int up = h[v]-h[u];

    for(int i = LOGN-1; i >= 0; i--)
        if((up >> i)&1) v = par[v][i];

    assert(h[u] == h[v]);

    if(u == v) return u;

    for(int i = LOGN-1; i >= 0; i--) {
        if(par[v][i] != par[u][i]) {
            v = par[v][i];
            u = par[u][i];
        }
    }

    return par[v][0];
}

struct Node {
    int maxh, plca, sumh;

    Node() {
        maxh = 0;
        plca = -1;
        sumh = 0;
    };
};

Node t[4 * maxn];
int a[maxn];

Node combine(const Node& a, const Node& b) {
    Node c;
    c.maxh = max(a.maxh, b.maxh);
    c.sumh = a.sumh + b.sumh;
    c.plca = lca(a.plca, b.plca);
    return c;
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v].maxh = h[a[tl]];
        t[v].sumh = h[a[tl]];
        t[v].plca = a[tl];
    }
    else {
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm+1, tr);

        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

void update(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return;
    if(tl == l and tr == r and t[v].maxh == 0) return;
    if(tl == tr) {
        a[tl] = phi[a[tl]];

        t[v].maxh = h[a[tl]];
        t[v].sumh = h[a[tl]];
        t[v].plca = a[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    update(v * 2, tl, tm, l, min(r, tm));
    update(v * 2 + 1, tm+1, tr, max(tm+1, l), r);

    t[v] = combine(t[v * 2], t[v * 2 + 1]);
}

Node query(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) {
        return Node();
    }
    if(tl == l and tr == r) return t[v];
    else {
        int tm = (tl + tr) >> 1;
        return combine(query(v * 2, tl, tm, l, min(r, tm)),
                query(v * 2 + 1, tm+1, tr, max(tm+1, l), r));
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sieve();

    build_tree();

    dfs(1);
    
    int n, m; cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    build(1, 0, n-1);

    for(int i = 0; i < m; i++) {
        int op; cin >> op;
        int l, r; cin >> l >> r;
        l--; r--;
        if(op == 1) {
            update(1, 0, n-1, l, r);
        }
        else {
            Node c = query(1, 0, n-1, l, r);
            cout << c.sumh - (r-l+1) * h[c.plca] << "\n";
        }
    }
	
    return 0;
}


