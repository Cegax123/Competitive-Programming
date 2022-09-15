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

vi adj[maxn];
int s[maxn];
ll t[4*maxn];

int ver[maxn];
int tin[maxn], tout[maxn];
int timer = 0;

void dfs(int v, int p) {
    tin[v] = timer++;
    ver[tin[v]] = v;

    for(int to : adj[v]) {
        if(to == p) continue;

        dfs(to, v);
    }

    tout[v] = timer-1;
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = s[ver[tl]];
    }
    else {
        int tm = (tl+tr) >> 1;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);

        t[v] = t[v*2] + t[v*2+1];
    }
}

void update(int v, int tl, int tr, int pos, int n_val) {
    if(tl == tr) {
        t[v] += n_val - s[ver[tl]];
        s[ver[tl]] = n_val;
    }
    else {
        int tm = (tl+tr) >> 1;
        if(pos <= tm) update(v*2, tl, tm, pos, n_val);
        else update(v*2+1, tm+1, tr, pos, n_val);

        t[v] = t[v*2] + t[v*2+1];
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    if(tr < l or tl > r) return 0;
    if(tl == l and tr == r) 
        return t[v];
    else {
        int tm = (tl+tr) >> 1;

        return query(v*2, tl, tm, l, min(tm, r)) + query(v*2+1, tm+1, tr, max(tm+1, l), r);
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
    build(1, 0, n-1);

    while(q--) {
        int op; cin >> op;

        if(op == 1) {
            int v, x; cin >> v >> x;
            v--;
            update(1, 0, n-1, tin[v], x);
        }
        else {
            int v; cin >> v;
            v--;

            cout << query(1, 0, n-1, tin[v], tout[v]) << "\n";
        }
    }
	
	return 0;
}

