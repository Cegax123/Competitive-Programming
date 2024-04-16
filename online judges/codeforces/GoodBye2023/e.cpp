#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
int n;
vector<int> adj[maxn], child[maxn];
int a[maxn], last[maxn], sz[maxn], pos[maxn], ind;

void dfs1(int u, int p=-1) {
    sz[u] = 1;
    pos[u] = ind++;

    int blast = last[a[u]];

    if(blast != -1) {
        child[blast].push_back(u);
    }

    last[a[u]] = u;

    for(int to : adj[u]) if(to != p) {
        dfs1(to, u);
        sz[u] += sz[to];
    }

    last[a[u]] = blast;
}

int t[4 * maxn], lazy[4 * maxn];

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = 0;
        lazy[v] = 0;
    }
    else {
        int tm = (tl+tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm+1, tr);

        t[v] = 0;
        lazy[v] = 0;
    }
}

void push(int v) {
    t[v * 2] += lazy[v];
    lazy[v * 2] += lazy[v];

    t[v * 2 + 1] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];

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
        int tm = (tl + tr) >> 1;
        update(v * 2, tl, tm, l, min(r, tm), delta);
        update(v * 2 + 1, tm+1, tr, max(tm+1, l), r, delta);

        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return 0;
    if(tl == l and tr == r) {
        return t[v];
    }
    else {
        push(v);
        int tm = (tl + tr) >> 1;
        return max(query(v * 2, tl, tm, l, min(r, tm)),
                query(v * 2 + 1, tm+1, tr, max(tm+1, l), r));
    }
}

long long ans;

void dfs2(int v, int p=-1) {
    for(int to : adj[v]) if(to != p) {
        dfs2(to, v);
    }

    update(1, 0, n-1, pos[v], pos[v] + sz[v] - 1, 1);
    for(int x : child[v]) {
        update(1, 0, n-1, pos[x], pos[x] + sz[x] - 1, -1);
    }

    vector<int> cc;
    for(int to : adj[v]) if(to != p) {
        cc.push_back(query(1, 0, n-1, pos[to], pos[to] + sz[to] - 1));
    }

    sort(cc.begin(), cc.end());
    reverse(cc.begin(), cc.end());

    if((int) cc.size() > 1) ans = max(ans, cc[0] * 1ll * cc[1]);
    else if(!cc.empty()) ans = max(ans, (long long) cc[0]);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(last, -1, sizeof(last));
    int t; cin >> t;
    while(t--) {
        cin >> n;

        for(int i = 1; i < n; i++) {
            int p; cin >> p; p--;
            adj[i].push_back(p);
            adj[p].push_back(i);
        }

        for(int i = 0; i < n; i++) cin >> a[i];

        ind = 0;

        dfs1(0);

        build(1, 0, n-1);

        ans = 1;
        dfs2(0);

        cout << ans << "\n";

        for(int i = 0; i < n; i++) {
            adj[i].clear();
            child[i].clear();
        }
    }

	
    return 0;
}


