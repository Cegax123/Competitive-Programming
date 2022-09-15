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

const int maxn = 4e5+5;

struct Edge {
	int to, id;
};

int n, m;
vector<Edge> adj[maxn];
int tin[maxn], low[maxn], timer = 0;
bool vis[maxn], isBridge[maxn];
vector<Edge> bridges[maxn];
vii ans(maxn);

void dfs(int v, int p = -1) {
	vis[v] = 1;
	tin[v] = low[v] = timer++;

	for(auto& e : adj[v]) {
		int to = e.to, id = e.id;

		if(to == p) continue;
		if(vis[to]) low[v] = min(low[v], tin[to]);
		else {
			dfs(to, v);
			low[v] = min(low[v], low[to]);

			if(low[to] > tin[v]) {
				isBridge[id] = 1;

				bridges[to].pb({v, id});
				bridges[v].pb({to, id});
			}
		}
	}
}

int idv[maxn], sz, mx = 0, mxid;
vi vbridges[maxn];

void dfs2(int v, int ind) {
	sz++;
	idv[v] = ind;

	bool isVbridge = false;

	for(auto& e : adj[v]) {
		int to = e.to, id = e.id;

		if(isBridge[id]) {
			isVbridge = true;
			continue;
		}

		if(idv[to] == 0) {
			dfs2(to, ind);
		}
	}

	if(isVbridge) vbridges[ind].pb(v);
}

void dfs_tree(int curr_id, int p = -1) {
	for(int v : vbridges[curr_id]) {
		for(auto& e : bridges[v]) {
			int to = e.to, id = e.id;

			if(idv[to] == p) continue;

			ans[id].first = to;
			ans[id].second = v;

			dfs_tree(idv[to], curr_id);
		}
	}
}

void get_tree_ans() {
	int ind = 1;
	for(int i = 0; i < n; i++) {
		if(idv[i] == 0) {
			sz = 0;
			dfs2(i, ind);

			if(sz > mx) {
				mx = sz;
				mxid = ind;
			}

			ind++;
		}
	}

	dfs_tree(mxid);
}

void dfs3(int v) {
	vis[v] = 1;

	for(auto& e : adj[v]) {
		int to = e.to, id = e.id;

		if(!isBridge[id]) {
			ans[id].first = v;
			ans[id].second = to;

			isBridge[id] = 1;
		}
		if(!vis[to])
			dfs3(to);
	}
}

void get_component_ans() {
	for(int i = 0; i < n; i++) {
		if(!vis[i]) dfs3(i);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;

		adj[a].pb({b, i});
		adj[b].pb({a, i});
	}

	dfs(0);

	get_tree_ans();

	memset(vis, 0, sizeof(vis));
	get_component_ans();

	cout << mx << "\n";

	for(int i = 0; i < m; i++)
		cout << ans[i].first+1 << " " << ans[i].second+1 << "\n";
	
	return 0;
}

