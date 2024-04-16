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

vi adj[maxn];
vi a;
int pos[maxn];
int h[maxn];
int sz[maxn];
ii t[4 * maxn];
int lazy[4 * maxn];

void dfs(int v=0) {
    pos[v] = a.size();
    a.pb(v);
    sz[v] += 1;

    for(int to : adj[v]) {
        h[to] = h[v] + 1;
        dfs(to);
        sz[v] += sz[to];
    }
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = {h[a[tl]], a[tl]};
    }
    else {
        int tm = (tl+tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);

        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

void push(int v) {
    t[v * 2].first += lazy[v];
    lazy[v * 2] += lazy[v];

    t[v * 2 + 1].first += lazy[v];
    lazy[v * 2 + 1] += lazy[v];

    lazy[v] = 0;
}

void modify(int v, int tl, int tr, int l, int r, int x) {
    if(tr < l or r < tl) return;
    if(tl == l and tr == r) {
        t[v].first += x;
        lazy[v] += x;
    }
    else {
        push(v);

        int tm = (tl + tr) >> 1;
        modify(v * 2, tl, tm, l, min(r, tm), x);
        modify(v * 2 + 1, tm+1, tr, max(tm+1, l), r, x);

        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k; cin >> n >> k;
    int pa[n];
    for(int i = 1; i < n; i++) {
        int p; cin >> p;
        p--;
        pa[i] = p;
        adj[p].pb(i);
    }

    h[0] = 1;

    dfs();
    build(1, 0, n-1);

    int ans = 0;

    vector<bool> vis(n, 0);

    for(int i = 0; i < k; i++) {
        ans += t[1].first;
        int v = t[1].second;

        while(!vis[v]) {
            vis[v] = 1;
            modify(1, 0, n-1, pos[v], pos[v] + sz[v]-1, -1);
            if(v) v = pa[v];
            else break;
        }
    }

    cout << ans << "\n";

    return 0;
}


