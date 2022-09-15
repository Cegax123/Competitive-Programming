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
int tin[maxn], low[maxn], timer = 0;
bool vis[maxn], isBridge[maxn];

struct Edge {
	int to, id;
};

vector<Edge> adj[maxn];
ii edges[maxn];

void dfs(int v, int p = -1) {
	vis[v] = true;
	tin[v] = low[v] = timer++;

	for(auto& e : adj[v]) {
		int to = e.to, id = e.id;

		if(to == p) continue;
		
		if(vis[to]) {
			low[v] = min(low[v], tin[to]);
		}
		else { 
			dfs(to, v);
			low[v] = min(low[v], low[to]); 

			if(low[to] > tin[v]) {
				isBridge[id] = 1;
			}
		}
	}
}

int ind = 1, node[maxn];
vi tree[maxn];
int idv[maxn];

struct Diam {
	int x, y, len = -1;
};

Diam get_max(const Diam& a, const Diam& b) {
	if(a.len > b.len) return a;
	return b;
}

bool comp(const Diam& a, const Diam& b) {
	return a.len < b.len;
}

Diam sum(const Diam& a, const Diam& b) {
	Diam result;

	result.len = a.len + b.len;
	if(a.x == b.x) {
		result.x = a.y; result.y = b.y;
	}
	else if(a.x == b.y) {
		result.x = a.y; result.y = b.x;
	}
	else if(a.y == b.x) {
		result.x = a.x; result.y = b.y;
	}
	else {
		result.x = a.x; result.y = b.x;
	}

	return result;
}

pair<Diam, Diam> diameter(int v, int p = -1) {
	Diam diam; diam.len = 0; diam.x = diam.y = v;

	vector<Diam> mxHeights(3);

	for(int to : tree[v]) {
		if(p == to) continue;

		pair<Diam, Diam> res = diameter(to, v);
		diam = get_max(diam, res.first);

		mxHeights[0] = res.second; mxHeights[0].len++; 
		if(mxHeights[0].x == to) mxHeights[0].x = v;
		else mxHeights[0].y = v;
		
		sort(all(mxHeights), comp);
	}

	for(int i = 0; i < 3; i++) {
		if(mxHeights[i].len == -1) {
			mxHeights[i].x = mxHeights[i].y = v;
			mxHeights[i].len = 0;
		}
	}

	diam = get_max(diam, sum(mxHeights[1], mxHeights[2]));

	return {diam, mxHeights[2]};
}

void dfs2(int v) {
	idv[v] = ind;

	for(auto& e: adj[v]) {
		int to = e.to, id = e.id;

		if(isBridge[id]) continue;

		if(idv[to] == 0) 
			dfs2(to);
	}
}

void mark_nodes() {
	memset(vis, 0, sizeof(vis));

	for(int i = 0; i < n; i++) {
		if(idv[i]) continue;

		node[ind] = i;
		dfs2(i);
		ind++;
	}
}

void build_tree() {
	for(int i = 0; i < m; i++) {
		if(isBridge[i] and idv[edges[i].first] != idv[edges[i].second]) {
			int ida = idv[edges[i].first], idb = idv[edges[i].second];
			tree[ida].pb(idb);
			tree[idb].pb(ida);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ifstream in; ofstream out;

	in.open("input.txt");
	out.open("output.txt");

	in >> n >> m;

	int sx, sy;
		
	for(int i = 0; i < m; i++) {
		int x, y; in >> x >> y;
		sx = x, sy = y;

		x--; y--;

		adj[x].pb({y, i});
		adj[y].pb({x, i});
		edges[i].first = x; edges[i].second = y;
	}

	dfs(0);
	mark_nodes();
	build_tree();

	if(ind == 2) {
		out << sx << " " << sy << "\n";
		return 0;
	}

	auto P = diameter(1);

	out << node[P.first.x]+1 << " " << node[P.first.y] + 1 << "\n";
	
	return 0;
}
