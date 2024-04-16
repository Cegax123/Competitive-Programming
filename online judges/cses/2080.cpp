#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
vector<int> adj[maxn];

int sz[maxn], pi[maxn];
bool block[maxn];
int n, k;

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

int cnt[maxn];
long long ans = 0;
int max_dp;

void dfs(int v, int p, int flag, int depth=1) {
    if(flag == 0) {
        if(depth <= k) ans += cnt[k-depth];
    }
    else cnt[depth]++;

    max_dp = max(max_dp, depth);

    for(int to : adj[v]) if(to != p and !block[to]) {
        dfs(to, v, flag, depth+1);
    }
}

void decompose(int x, int p=-1, int m=n) {
    int cen = centroid(x, -1, m);
    if (~pi[cen]) sz[pi[cen]]=m-sz[cen];
    pi[cen]=p; block[cen]=1;

    cnt[0] = 1;

    max_dp = 0;
    for(int to : adj[cen]) if(!block[to]) {
        dfs(to, cen, 0);
        dfs(to, cen, 1);
    }

    fill(cnt+1, cnt+max_dp+1, 0);

    for (auto v : adj[cen]) if (!block[v]) {
        decompose(v, cen, sz[v]);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
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


