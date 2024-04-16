#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
const int E = 22;

int mask[maxn];
int sz[maxn];
int ver[maxn];
int h[maxn];

vector<pair<int, char>> adj[maxn];
int st[maxn], fin[maxn];
int T = 0;
int len[1 << E];

void predfs(int u, int p) {
    sz[u] = 1;
    st[u] = T++; 
    ver[st[u]] = u;

    if(u == p) h[u] = 1;
    else h[u] = h[p] + 1;


    for(auto [to, e] : adj[u]) if(to != p) {
        mask[to] = mask[u] ^ (1 << (e-'a'));
        predfs(to, u);
        sz[u] += sz[to];
    }

    fin[u] = T;
}

int ans[maxn];

void evaluate(int u, int v) {
    if(len[mask[v]])
        ans[u] = max(ans[u], len[mask[v]] + h[v] - 2 * h[u]);

    for(int i = 0; i < E; i++) {
        if(len[mask[v]^(1<<i)])
            ans[u] = max(ans[u], len[mask[v] ^ (1 << i)] + h[v] - 2 * h[u]);
    }
}


void dfs(int u, int p, bool keep=false) {
    int big_child = -1, mx_sz = 0;

    for(auto [to, e] : adj[u]) if(to != p) {
        if(sz[to] > mx_sz) {
            mx_sz = sz[to];
            big_child = to;
        }
    }

    for(auto [to, e] : adj[u]) if(to != p and to != big_child) {
        dfs(to, u, false);
        ans[u] = max(ans[u], ans[to]);
    }

    if(big_child != -1) {
        dfs(big_child, u, true);
        ans[u] = max(ans[u], ans[big_child]);
    }

    //if(u == 1) {
        //for(auto e : len) cout << e.first << " " << e.second << endl;
    //}

    evaluate(u, u);
    len[mask[u]] = max(len[mask[u]], h[u]);


    for(auto [to, e] : adj[u]) if(to != p and to != big_child) {
        for(int x = st[to]; x < fin[to]; x++) {
            int v = ver[x];
            evaluate(u, v);
        }
        for(int x = st[to]; x < fin[to]; x++) {
            int v = ver[x];
            len[mask[v]] = max(len[mask[v]], h[v]);
        }
    }

    if(!keep) {
        for(int x = st[u]; x < fin[u]; x++) {
            int v = ver[x];
            len[mask[v]] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i < n; i++) {
        int p; cin >> p; p--;
        char c; cin >> c;
        
        adj[i].push_back({p, c});
        adj[p].push_back({i, c});
    }
    
    predfs(0, 0);

    //for(int i = 0;  i< n; i++ )cout << mask[i] << " ";
    //cout << endl;

    dfs(0, 0);

    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}

