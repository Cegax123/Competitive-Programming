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
const int LOGN = 20;

vi adj[maxn];
int h[maxn];
int up[maxn][LOGN];
int timer = 0;
int st[maxn], fin[maxn];

void dfs(int u, int p) {
    if(u == p) h[u] = 0;
    else h[u] = h[p] + 1;

    up[u][0] = p;

    st[u] = timer++;

    for(int i = 1; i < LOGN; i++) {
        up[u][i] = up[up[u][i-1]][i-1];
    }

    for(int to : adj[u]) if(to != p) {
        dfs(to, u);
    }

    fin[u] = timer++;
}

bool is_parent(int u, int v) {
    return st[u] <= st[v] and fin[v] <= fin[u];
}

int lca(int u, int v) {
    if(is_parent(u, v)) return u;
    if(is_parent(v, u)) return v;

    for(int i = LOGN-1; i >= 0; i--) {
        if(!is_parent(up[u][i], v)) u = up[u][i];
    }

    return up[u][0];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q; cin >> n >> q;

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(0, 0);

    auto find = [&](int a, int b, int p, int c) {
        if(p == lca(a, c)) return lca(b, c);
        return lca(a, c);
    };

    while(q--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        a--; b--; c--; d--;

        if(h[a] > h[b]) swap(a, b);

        int p = lca(a, b);

        if(p == lca(p, c)) {
            if(p == lca(p, d)) {
                int x = lca(c, d);
                if(!is_parent(x, a) and !is_parent(x, b)) {
                    cout << 0 << "\n";
                    continue;
                }

                int pc = find(a, b, p, c), pd = find(a, b, p, d);
                int pcd = lca(pc, pd);

                cout << abs(h[pcd]-h[pc]) + abs(h[pcd]-h[pd]) + 1 << "\n";
            }
            else {
                int pc = find(a, b, p, c);

                cout << abs(h[pc]-h[p]) + 1 << "\n";
            }
        }
        else {
            if(p == lca(p, d)) {
                int pd = find(a, b, p, d);
                cout << abs(h[pd]-h[p]) + 1 << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }
    }
	
    return 0;
}


