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
const int LOGN = 20;

vi adj[maxn];
int timer = 0; 
int tin[maxn], tout[maxn];
int up[maxn][LOGN+1];
int h[maxn];

void dfs(int v, int p) {
    if(v == 0) h[v] = 0;
    else h[v] = h[p]+1;

    tin[v] = ++timer;
    up[v][0] = p;

    for(int i = 1; i <= LOGN; i++) 
        up[v][i] = up[up[v][i-1]][i-1];

    for(int to : adj[v]) {
        if(to == p) continue;

        dfs(to, v);
    }

    tout[v] = ++timer;
}

int get_kpar(int x, int k) {
    int ans = x;
    for(int i = 0; i < LOGN; i++)
        if((k >> i)&1)
            ans = up[ans][i];

    return ans;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = LOGN; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

vii child[maxn];
ii par[maxn];

void init() {
    for(int i = 0; i < maxn; i++)
        child[i].resize(3, {-1, -1});
}

void get_child(int v, int p = -1) {
    child[v][2] = {0, v};

    for(int to : adj[v]) {
        if(to == p) continue;;

        get_child(to, v);

        child[v][0] = child[to][2];
        child[v][0].first++;

        sort(all(child[v]));
    }
}

void get_par(int src=0) {
    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        int v = q.front(); q.pop();

        par[v] = {0, v};
        int pv = up[v][0];

        if(v) {
            int maxc = child[pv][2].second;

            if(!is_ancestor(v, maxc)) {
                par[v] = child[pv][2];
                par[v].first++;
            }
            else if(child[pv][1].first != -1) {
                par[v] = child[pv][1];
                par[v].first++;
            }

            if(par[v].first < par[pv].first+1) {
                par[v] = par[pv];
                par[v].first++;
            }
        }

        for(int to : adj[v]) {
            if(to != pv)
                q.push(to);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();

    int n; cin >> n;

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;

        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    dfs(0, 0);
    get_child(0);
    get_par(0);

    vii furthest(n);

    for(int i = 0; i < n; i++) {
        if(child[i][2].first > par[i].first)
            furthest[i] = child[i][2];
        else 
            furthest[i] = par[i];
    }

    int q; cin >> q;
    while(q--) {
        int u, d; cin >> u >> d;
        u--;

        if(d > furthest[u].first) {
            cout << -1 << "\n";
            continue;
        }

        int v = furthest[u].second;
        int p = lca(um v);
        
        int L = h[u]-h[p];
        int R = h[v]-h[p];

        if(d < L) {
            cout << get_kpar(u, d)+1 << "\n";
        }
        else {
            cout << get_kpar(v, R-d+L)+1 << "\n";
        }
    }
    
    return 0;
}


