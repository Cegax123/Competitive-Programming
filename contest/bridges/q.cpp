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

vi tin, low;
vector<bool> vis, isBridge;
vector<vii> adj;
int timer;
int n, m;

struct Edge {
	int u, v;
};

vector<Edge> edges;

void init() {
	vis.clear(); vis.resize(n, 0);
	tin.clear(); tin.resize(n, -1);
	low.clear(); low.resize(n, -1);
	isBridge.clear(); isBridge.resize(m, 0);
	adj.clear(); adj.resize(n);
	edges.clear();

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

vi c;
vector<vi> tree;

void assign_color(int v, int ind) {
	c[v] = ind;

	for(auto e : adj[v]) {
		int to = e.first, id = e.second;

		if(isBridge[id]) continue;
		if(c[to] != -1) continue;

		assign_color(to, ind);
	}
}

void build_tree() {
	c.clear(); c.resize(n, -1);
	int ind = 0;

	for(int i = 0; i < n; i++) {
		if(c[i] == -1) {
			assign_color(i, ind);
			ind++;
		}
	}

	tree.clear(); tree.resize(ind+5);

	for(int i = 0; i < m; i++) {
		int u = c[edges[i].u], v = c[edges[i].v];
		if(isBridge[i] and u != v) {
			tree[u].pb(v);
			tree[v].pb(u);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	
	init();

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;

		adj[a].pb({b, i});
		adj[b].pb({a, i});
		edges.pb({a, b});
	}

	dfs(0, -1);
	build_tree();

	if((int) tree.size() <= 2) cout << "YES\n";
	else {
		bool comp = 1;

		for(int i = 0; i < (int) tree.size(); i++) 
			if((int) tree[i].size() > 2) comp = 0;
		cout << (comp ? "YES\n" : "NO\n");
	}

	return 0;
}
