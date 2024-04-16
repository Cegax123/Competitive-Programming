#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

const int maxd = 20000;
vector<int> change[maxd+1];

const int maxn = 1e5 + 5;
vector<pair<int, int>> adj[maxn];

const int LOGN = 17;

int c[maxn];
int curr[maxn];
int sum[maxn];
int node[maxn];
int up[maxn][LOGN];

vector<int> posval[maxn];
int st[maxn], fin[maxn];
int sz[maxn];
int pos[maxn];
vector<int> euler;
int timer = 0;

void dfs(int v, int p) {
    pos[v] = euler.size();
    node[euler.size()] = v;
    euler.push_back(v);

    up[v][0] = p;
    sz[v] = 1;

    sum[v] = c[v] + sum[p];

    for(int i = 1; i < LOGN; i++) {
        up[v][i] = up[up[v][i-1]][i-1];
    }

    st[v] = timer++;

    for(auto [to, w] : adj[v]) if(to != p) {
        c[to] = w;
        curr[to] = w;
        posval[w].push_back(to);

        dfs(to, v);

        sz[v] += sz[to];
    }

    fin[v] = timer++;
}

bool is_parent(int u, int v) {
    return st[u] <= st[v] and fin[v] <= fin[u];
}

int lca(int u, int v) {
    if(is_parent(u, v)) return u;
    if(is_parent(v, u)) return v;

    for(int i = LOGN-1; i >= 0; i--) {
        if(!is_parent(up[u][i], v)) {
            u = up[u][i];
        }
    }

    return up[u][0];
}

int t[4 * maxn], lazy[4 * maxn];

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = sum[node[tl]];
    }
    else {
        int tm = (tl+tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm+1, tr);

        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int ceil(int x, int y) {
    return (x+y-1) / y;
}

void push(int v) {
    t[v * 2] = ceil(t[v*2], lazy[v]);
    t[v * 2+1] = ceil(t[v*2+1], lazy[v]);
    lazy[v * 2] = ;
    lazy[v * 2] = ceil(t[v*2], lazy[v]);

    t[v * 2] += lazy[v];
    t[v * 2+1] += lazy[v];
    lazy[v * 2] += lazy[v];
    lazy[v * 2+1] += lazy[v];
    
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int delta) {
    if(tr < l or r < tl) return;
    if(tl == l and tr == r) {
        t[v] += delta;
        lazy[v] += delta;
    }
    else {
        push(v);
        int tm = (tl+tr) >> 1;
        update(v * 2, tl, tm, l, min(r, tm), delta);
        update(v * 2 + 1, tm+1, tr, max(tm+1, l), r, delta);

        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int query(int v, int tl, int tr, int pos) {
    if(tl == tr) return t[v];
    else {
        push(v);
        int tm = (tl+tr) >> 1;
        if(pos <= tm) return query(v * 2, tl, tm, pos);
        else return query(v * 2 + 1, tm+1, tr, pos);
    }
}

struct Query {
    int u, v, id;
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 


    for(int i = 1; i <= maxd; i++) {
        int res = i;
        for(int x = 2; x * x <= i; x++) {
            change[x].push_back(i);
            res = (i+x-1)/x;
        }

        for(int y = res-1; y >= 1; y--) {
            int x = (i+y-1) / y;
            change[x].push_back(i);
        }

        if(i+1 <= maxd) {
            change[i+1].push_back(i);
        }
    }

    int n, q; cin >> n >> q;
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        int w; cin >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs(0, 0);
    build(1, 0, n-1);

    vector<Query> queries[maxd+1];

    for(int i = 0; i < q; i++) {
        int u, v, d; cin >> u >> v >> d;
        u--; v--;

        queries[d].push_back({u, v, i});
    }

    int ans[q];

    for(int i = 1; i <= maxd; i++) {
        for(int x : change[i]) {
            int new_val = (x + i - 1) / i;
            int bef_val = (x + i - 2) / (i-1);

            int delta = new_val - bef_val;

            for(int v : posval[x]) {
                update(1, 0, n-1, pos[v], pos[v]+sz[v]-1, delta);
            }
        }

        for(Query q : queries[i]) {
            int u = q.u; int v = q.v;
            int p = lca(u, v);

            int qu = query(1, 0, n-1, pos[u]), qv = query(1, 0, n-1, pos[v]), qp = query(1, 0, n-1, pos[p]);

            ans[q.id] = (qu - qp) + (qv - qp) + 1;
        }
    }

    for(int i = 0; i < q; i++) cout << ans[i] << "\n";

    return 0;
}
