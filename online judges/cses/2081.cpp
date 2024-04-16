#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

int t[4 * maxn];
bool zero[4 * maxn];

void push(int v) {
    if(zero[v]) {
        t[v * 2] = 0;
        zero[v * 2] = 1;

        t[v * 2 + 1] = 0;
        zero[v * 2 + 1] = 1;

        zero[v] = 0;
    }
}

void addone(int v, int tl, int tr, int pos) {
    if(tl == tr) {
        t[v]++;
    }
    else {
        push(v);
        int tm = (tl+tr) >> 1;
        if(pos <= tm) addone(v * 2, tl, tm, pos);
        else addone(v * 2 + 1, tm+1, tr, pos);

        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

void update_zero(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return;
    if(tl == l and tr == r) {
        t[v] = 0;
        zero[v] = 1;
    }
    else {
        push(v);
        int tm = (tl+tr) >> 1;
        update_zero(v * 2, tl, tm, l, min(r, tm));
        update_zero(v * 2 + 1, tm+1, tr, max(tm+1, l), r);

        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return 0;
    if(tl == l and tr == r) {
        return t[v];
    }
    else {
        push(v);
        int tm = (tl+tr) >> 1;
        return query(v * 2, tl, tm, l, min(r, tm)) +
                query(v * 2 + 1, tm+1, tr, max(tm+1, l), r);
    }
}

vector<int> adj[maxn];
int sz[maxn], pi[maxn];
bool block[maxn];
int n, l, r;

int centroid(int v, int p, int n) {
    sz[v] = 1;
    int mx=0, cen=0;
    for (auto u : adj[v]) if (u!=p && !block[u]) {
        cen ^= centroid(u, v, n);
        sz[v] += sz[u], mx=max(mx, sz[u]);
    }
    mx = max(mx, n-sz[v]);
    if (2*mx <= n) pi[cen=v]=p;
    return cen;
}

int max_depth;
long long ans = 0;

void dfs(int v, int p, bool fill, int depth=1) {
    max_depth = max(max_depth, depth);
    if(fill) addone(1, 0, n-1, depth);
    else {
        int L = max(0, l-depth), R = r-depth;
        if(R >= 0) {
            ans += query(1, 0, n-1, L, R);
        }
    }

    for(int to : adj[v]) if(to != p and !block[to]) {
        dfs(to, v, fill, depth+1);
    }
}

void decompose(int x, int p=-1, int m=n) {
    int cen = centroid(x, -1, m);
    if (~pi[cen]) sz[pi[cen]]=m-sz[cen];
    pi[cen]=p; block[cen]=1;

    max_depth = 0;
    addone(1, 0, n-1, 0);
    for(int to : adj[cen]) if(!block[to]) {
        dfs(to, cen, 0);
        dfs(to, cen, 1);
    }

    update_zero(1, 0, n-1, 0, max_depth);

    for (auto v : adj[cen]) if (!block[v]) {
        decompose(v, cen, sz[v]);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> l >> r;
    for(int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    decompose(0);

    cout << ans << "\n";
	
    return 0;
}


