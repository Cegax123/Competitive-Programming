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

int tin[maxn], tout[maxn], ver[maxn], timer = 0;
int s[maxn];
ll val[maxn];
int p[maxn];
vi adj[maxn];

void dfs(int v, int par) {
    tin[v] = timer++;
    ver[tin[v]] = v;

    val[v] = s[v];
    if(v) val[v] += val[par];

    for(int to : adj[v]) {
        if(to == par) continue;

        dfs(to, v);
    }

    tout[v] = timer-1;
}

ll lazy[4*maxn];

void push(int v) {
    lazy[v*2] += lazy[v];
    lazy[v*2+1] += lazy[v];

    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int x) {
    if(tl > r or tr < l) 
        return;
    if(tl == l and tr == r) {
        lazy[v] += x;
    }
    else {
        push(v);

        int tm = (tl+tr) >> 1;

        update(2*v, tl, tm, l, min(r, tm), x);
        update(2*v+1, tm+1, tr, max(tm+1, l), r, x);
    }
}

ll query(int v, int tl, int tr, int pos) {
    if(tl == tr)
        return lazy[v];
    else {
        push(v);

        int tm = (tl+tr) >> 1;

        if(pos <= tm) return query(v*2, tl, tm, pos);
        else return query(v*2+1, tm+1, tr, pos);
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, q; cin >> n >> q;
	
    for(int i = 0; i < n; i++)
        cin >> s[i];

    for(int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(0, 0);

    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int v, x; cin >> v >> x;
            v--;

            update(1, 0, n-1, tin[v], tout[v], x-s[v]);
            s[v] = x;
        }
        else {
            int v; cin >> v;
            v--;

            cout << val[v] + query(1, 0, n-1, tin[v]) << "\n";
        }
    }
	
	return 0;
}

