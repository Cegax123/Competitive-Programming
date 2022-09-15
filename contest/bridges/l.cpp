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

int tin[maxn], low[maxn];
int n, m;
vector<vii> adj;
vector<bool> vis, is_bridge;
vii edges;
int timer;

void init() {
	adj.clear(); adj.resize(n);
	vis.clear(); vis.resize(n, 0);
	is_bridge.clear(); is_bridge.resize(m, 0);
	edges.clear();
	timer = 0;
}

void dfs(int v, int p = -1) {
	vis[v] = 1;
	tin[v] = low[v] = timer++;

	for(auto e : adj[v]) {
		int to = e.first, id = e.second;
		if(to == p) continue;
		if(vis[to]) {
			low[v] = min(low[v], tin[to]);
		}
		else {
			dfs(to, v);
			low[v] = min(low[v], low[to]);

			if(low[to] > tin[v]) {
				is_bridge[id] = 1;
			}
		}
	}
}

vector<vi> tree;
vi idv;

void assign_id(int v, int ind) {
	idv[v] = ind;

	for(auto e : adj[v]) {
		int to = e.first, id = e.second;

		if(idv[to] != -1 or is_bridge[id]) continue;

		assign_id(to, ind);
	}
}

int solve() {
	idv.clear(); idv.resize(n, -1);

	int k = 0;
	for(int i = 0; i < n; i++) {
		if(idv[i] == -1) {
			assign_id(i, k);
			k++;
		}
	}

	tree.clear(); tree.resize(k);
	for(int i = 0; i < m; i++) {
		int u = edges[i].first, v = edges[i].second;
		if(is_bridge[i] and idv[u] != idv[v]) {
			u = idv[u], v = idv[v];
			tree[u].pb(v);
			tree[v].pb(u);
		}
	}

	if(k == 1) return 0;

	int ans = 0;
	for(int i = 0; i < k; i++) {
		if(tree[i].size() == 1)
			ans++;
	}

	return (ans+1)/2;
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
			edges.pb({a, b});
		}

		dfs(0);

		cout << "Case " << tc << ": ";
		cout << solve() << "\n";
	}
	
	
	return 0;
}
