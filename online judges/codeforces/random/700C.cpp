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

const int maxn = 1000+5;
const int maxm = 3e4+5;
const int INF = 1e9+7;

int n, m;
int s, t;

struct Edge {
	int to, w, id;
};

ii edges[maxm];
int W[maxm];

vector<Edge> adj[maxn];
bool vis[maxn];

void dfs(int v) {
	vis[v] = 1;

	for(auto& e : adj[v]) {
		int to = e.to;
		if(vis[to]) continue;
		dfs(to);
	}
}

int idv[maxn], ans, val, timer;
bool isBridge[maxm];
bool deleted[maxm];
int low[maxn], tin[maxn];

void mark_bridges(int v, int p = -1) {
	vis[v] = true;
	tin[v] = low[v] = timer++;

	for(auto& e : adj[v]) {
		int to = e.to, id = e.id;
		
		if(to == p) continue;
		if(deleted[id]) continue;

		if(vis[to]) {
			low[v] = min(low[v], tin[to]);
		}
		else {
			mark_bridges(to, v);
			low[v] = min(low[v], low[to]);
			
			if(low[to] > tin[v]) {
				isBridge[id] = 1;
			}
		}
	}
}

void mark_nodes(int v) {
	idv[v] = val;

	for(auto& e : adj[v]) {
		int to = e.to, id = e.id;

		if(deleted[id]) continue;
		if(isBridge[id]) continue;

		if(idv[to] == 0) 
			mark_nodes(to);
	}
}

vii tree[maxn];
vi min_bridge;
vi ans_bridge;

void get_min_bridge(int v, int p = -1) {
	for(auto& e : tree[v]) {
		int to = e.first, id = e.second;
		int w = W[id];
		if(to == p) continue;

		if(w < min_bridge[v]) {
			min_bridge[to] = w;
			ans_bridge[to] = id;
		}
		else {
			min_bridge[to] = min_bridge[v];
			ans_bridge[to] = ans_bridge[v];
		}

		get_min_bridge(to, v);
	}
}

bool solve_with_bridges() {
	memset(vis, 0, sizeof(vis));
	memset(low, 0, sizeof(low));
	memset(tin, 0, sizeof(tin));
	memset(isBridge, 0, sizeof(isBridge));
	memset(idv, 0, sizeof(idv));

	for(int i = 0; i < maxn; i++)
		tree[i].clear();

	min_bridge.clear();
	min_bridge.resize(maxn, INF);

	ans_bridge.clear();
	ans_bridge.resize(maxn);
	
	timer = 0;
	mark_bridges(s);

	val = 1;
	for(int i = 0; i < n; i++) {
		if(vis[i] and idv[i] == 0) {
			val++;
			mark_nodes(i);
		}
	}

	if(idv[s] == idv[t]) return false;
	
	for(int i = 0; i < m; i++) {
		int ida = idv[edges[i].first], idb = idv[edges[i].second];
		if(isBridge[i] and ida != idb) {
			tree[ida].pb({idb, i});
			tree[idb].pb({ida, i});
		} 
	}

	get_min_bridge(idv[s]);
	return true;
}

ii p[maxn];

void dfs2(int v) {
	vis[v] = 1;

	for(auto& e : adj[v]) {
		int to = e.to, id = e.id;

		if(vis[to]) continue;

		p[to] = {v, id};
		dfs2(to);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m >> s >> t;
	s--; t--;

	for(int i = 0; i < m; i++) {
		int a, b, w; cin >> a >> b >> w;
		a--; b--;
		
		adj[a].pb({b, w, i});
		adj[b].pb({a, w, i});

		edges[i].first = a;
		edges[i].second = b;
		W[i] = w;
	}

	dfs(s);

	if(vis[t] == false) {
		cout << "0\n0\n";
		return 0;
	}

	int ans = (int) 2e9+7;
	vi vans;

	bool result = solve_with_bridges();

	if(result) {
		int id = ans_bridge[idv[t]];

		ans = W[id];
		vans.pb(id+1);
	}
	
	memset(vis, 0, sizeof(vis));
	dfs2(s);

	vi edges_id;
	int temp = t;

	while(temp != s) {
		edges_id.pb(p[temp].second);
		temp = p[temp].first;
	}

	for(int edge : edges_id) {
		deleted[edge] = 1;

		result = solve_with_bridges();

		if(result) {
			int id = ans_bridge[idv[t]];
			int temp_ans = W[edge] + W[id];

			if(temp_ans < ans) {
				ans = temp_ans;
				vans.clear();
				vans.pb(edge+1);
				vans.pb(id+1);
			}
		}

		deleted[edge] = 0;
	}

	if(ans == (int) 2e9+7) {
		cout << "-1\n";
	}
	else {
		cout << ans << "\n";
		cout << vans.size() << "\n";
		for(int x : vans) 
			cout << x << " ";
		cout << "\n";
	}
	
	return 0;
}

