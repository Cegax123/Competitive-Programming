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

const int maxn = 1e5+5;
int n, m;

struct Edge {
	int a, b, w, id;
};

vector<vector<Edge>> adj;
vector<Edge> edges;
int tin[maxn], low[maxn];
int timer;
vector<bool> vis, is_bridge;

void init() {
	adj.clear(); adj.resize(n);
	edges.clear();
	vis.clear(); vis.resize(n, 0);
	is_bridge.clear(); is_bridge.resize(m, 0);
	timer = 0;
}

void dfs(int v, int p) {
	vis[v] = 1;
	tin[v] = low[v] = timer++;

	for(auto e : adj[v]) {
		int to = e.b, id = e.id;

		if(p == to) continue;

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

vector<vii> tree;
vector<vector<ll> > d;
vi idv, ver;
int k;

ll maxd;
int V;

void assign_id(int v, int ind) {
	idv[v] = ind;

	for(auto e : adj[v]) {
		int to = e.b, id = e.id;

		if(idv[to] != -1 or is_bridge[id]) continue;

		assign_id(to, ind);
	}
}

void build_tree() {
	idv.clear(); idv.resize(n, -1);
	ver.clear();

	k = 0;
	for(int i = 0; i < n; i++) {
		if(idv[i] == -1) {
			ver.pb(i);
			assign_id(i, k++);
		}
	}

	tree.clear(); tree.resize(k);
	d.clear(); d.resize(k, vector<ll>(3, -1ll));

	maxd = (ll) 1e18;
	V = 0;

	for(int i = 0; i < m; i++) {
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		if(is_bridge[i] and idv[a] != idv[b]) {
			tree[idv[a]].pb({idv[b], w});
			tree[idv[b]].pb({idv[a], w});
		}
	}
}

void calc_d(int v, int p = -1) {
	d[v][2] = 0;

	for(auto e : tree[v]) {
		int to = e.first; ll w = e.second;

		if(to == p) continue;

		calc_d(to, v);

		d[v][0] = w+d[to][2];
		sort(all(d[v]));
	}
}

void reroot(int v, int p = -1) {
	if(d[v][2] < maxd) {
		maxd = d[v][2];
		V = ver[v];
	}
	if(d[v][2] == maxd) 
		V = min(ver[v], V);

	for(auto e : tree[v]) {
		int to = e.first; ll w = e.second;

		if(to == p) continue;

		vector<ll> d_v = d[v];
		vector<ll> d_to = d[to];

		if(d[v][2] == w+d[to][2]) {
			d[v][2] = -1;
			sort(all(d[v]));
		}

		d[to][0] = d[v][2]+w;
		sort(all(d[to]));

		reroot(to, v);

		d[v] = d_v;
		d[to] = d_to;
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) {
		cin >> n >> m;

		init();

		for(int i = 0; i < m; i++) {
			int a, b, w; cin >> a >> b >> w;
			a--; b--;
			
			adj[a].pb({a, b, w, i});
			adj[b].pb({b, a, w, i});

			edges.pb({a, b, w, i});
		}

		dfs(0, 0);
		build_tree();

		calc_d(0);
		reroot(0);

		cout << V+1 << " " << maxd << "\n";
	}
	
	
	return 0;
}
