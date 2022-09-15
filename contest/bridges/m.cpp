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

const int maxn = 1e4+5;

int n, m; 
int tin[maxn], low[maxn];
vector<bool> vis, isBridge;
vector<vii> adj; 
int timer;

void init() {
	vis.clear(); vis.resize(n, 0);
	isBridge.clear(); isBridge.resize(m, 0);
	adj.clear(); adj.resize(n);

	timer = 0;
}

void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    for (auto e : adj[v]) {
        int to = e.first, id = e.second;
        if (to == p) continue;
        if (vis[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                isBridge[id] = 1;
        }
    }
}

int sz;
bool is_bipartite;
vi c;

void dfs2(int v, int x) {
    sz++;
    c[v] = x;
    
    for(auto e : adj[v]) {
        int to = e.first, id = e.second;
        if(isBridge[id]) continue;
        if(c[to] != -1) {
            if(c[v] == c[to]) is_bipartite = 0;
        }
        else dfs2(to, 1-x);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;

	for(int tc = 1; tc <= t; tc++) {
		cin >> n >> m;

		init();

        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;

            adj[a].pb({b, i});
            adj[b].pb({a, i});
        }
		
        for(int i = 0; i < n; i++) 
            if(!vis[i]) dfs(i);

        c.clear(); c.resize(n, -1);
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(c[i] == -1) {
                sz = 0;
                is_bipartite = 1;

                dfs2(i, 0);

                if(!is_bipartite) ans += sz;
            }
        }

        cout << "Case " << tc << ": ";
        cout << ans << "\n";
	}
	
	
	return 0;
}
