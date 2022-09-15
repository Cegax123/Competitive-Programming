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

const int maxn = 2e5 + 5;
int t[4 * maxn];
bool change[4 * maxn];

int T = 0;
int a[maxn], sz[maxn], c[maxn], pos[maxn];
vi adj[maxn];

void dfs(int v, int p = -1) {
    a[T] = v;
    pos[v] = T;

    T++;

    sz[v] = 1;
    for(int to : adj[v]) {
        if(to == p) continue;
        dfs(to, v);
        sz[v] += sz[to];
    }
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = c[tl];
    }
    else {
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm+1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

void apply(int v, int tl, int tr) {
    change[v] ^= 1;
    t[v] = tr-tl+1-t[v];
}

void push(int v, int tl, int tr) {
    if(change[v]) {
        int tm = (tl + tr) >> 1;
        apply(v * 2, tl, tm);
        apply(v * 2 + 1, tm+1, tr);
        change[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return;

    if(tl == l and tr == r) {
        apply(v, tl, tr);
    }
    else {
        push(v, tl, tr);

        int tm = (tl + tr) >> 1;
        update(v * 2, tl, tm, l, min(r, tm));
        update(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);

        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return 0;
    if(tl == l and tr == r)
        return t[v];
    else {
        push(v, tl, tr);

        int tm = (tl + tr) >> 1;
        return query(v * 2, tl, tm, l, min(r, tm)) + 
            query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
        int p; cin >> p;
        p--;

        adj[i].pb(p);
        adj[p].pb(i);
    }

    dfs(0);

    for(int i = 0; i < n; i++)
        cin >> c[pos[i]];

    build(1, 0, n-1);

    int q; cin >> q;
    while(q--) {
        string op; cin >> op;
        if(op == "get") {
            int v; cin >> v;
            v--;

            cout << query(1, 0, n-1, pos[v], pos[v] + sz[v] - 1) << "\n";
        }
        else {
            int v; cin >> v;
            v--;

            update(1, 0, n-1, pos[v], pos[v] + sz[v] - 1);
        }
    }
	
    return 0;
}


