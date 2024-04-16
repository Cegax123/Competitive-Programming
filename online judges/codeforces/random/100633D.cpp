#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;

vector<pair<int, int>> adj[maxn];

int sz[maxn], pi[maxn];
bool block[maxn];
int n;

const int LOGN = 20;
int st[maxn], fin[maxn];
int h[maxn];
int up[maxn][LOGN];
int timer;

void dfs(int v, int p) {
	if(v == p) h[v] = 0;

	st[v] = timer++;

	up[v][0] = p;
	for(int i = 1; i < LOGN; i++) {
		up[v][i] = up[up[v][i-1]][i-1];
	}

	for(auto [to, w] : adj[v]) if(to != p) {
		h[to] = h[v] + w;
		dfs(to, v);
	}

	fin[v] = timer++;
}

int centroid(int v, int p, int n) {
  sz[v] = 1;
  int mx=0, cen=0;
  for (auto [u, w] : adj[v]) if (u!=p && !block[u]) {
      cen ^= centroid(u, v, n);
      sz[v] += sz[u], mx=max(mx, sz[u]);
  }
  mx = max(mx, n-sz[v]);
  if (2*mx <= n) pi[cen=v]=p;
  return cen;
}

void decompose(int x, int p=-1, int m=n) {
  int cen = centroid(x, -1, m);
  if (~pi[cen]) sz[pi[cen]]=m-sz[cen];
  pi[cen]=p; block[cen]=1; for (auto [v, w] : adj[cen]) if (!block[v]) {
      decompose(v, cen, sz[v]);
  }
}

bool is_parent(int u, int v) {
	return st[u] <= st[v] and fin[v] <= fin[u];
}

int lca(int u, int v) {
	if(is_parent(u, v)) return u;
	if(is_parent(v, u)) return v;

	for(int i = LOGN-1; i >= 0; i--) {
		if(!is_parent(up[u][i], v)) u = up[u][i];
	}
	return up[u][0];
}

int dis(int u, int v) {
	int p = lca(u, v);
	return h[u] + h[v] - 2 * h[p];
}

struct Color {
	int d, c, i;
};

vector<Color> nodes[maxn];

void update(int v, int d, int c, int i) {
	while(!nodes[v].empty() and nodes[v].back().d <= d) nodes[v].pop_back();
	nodes[v].push_back({d, c, i});

	int u = v;

	while(pi[u] != -1) {
		u = pi[u];

		d -= dis(u, v);

		while(!nodes[u].empty() and nodes[u].back().d <= d) nodes[u].pop_back();
		nodes[u].push_back({d, c, i});

		d += dis(u, v);
	}
}

int query(int v) {
	vector<pair<int, int>> ans;

	int u = v;
	while(u != -1) {
		int d = dis(u, v);

		if(!nodes[u].empty()) {
			int l = 0, r = nodes[u].size()-1;

			while(l < r) {
				int m = (l+r+1) >> 1;
				if(nodes[u][m].d >= d) l = m;
				else r = m-1;
			}

			if(nodes[u][l].d >= d) ans.push_back({nodes[u][l].i, nodes[u][l].c});
		}

		u = pi[u];
	}

	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());

	if(ans.empty()) return 0;
	return ans[0].second;
}

int main() {
	cin >> n;
	for(int i = 0; i < n-1; i++) {
		int a, b, w; cin >> a >> b >> w;
		a--; b--;

		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}

	decompose(0);

	dfs(0, 0);
	
	int q; cin >> q;
	int cnt = 0;
	while(q--) {
		int op; cin >> op;
		if(op == 1) {
			int v, d, c; cin >> v >> d >> c;
			v--;
			update(v, d, c, cnt++);
		}
		else {
			int v; cin >> v;
			v--;
			cout << query(v) << "\n";
		}
	}

	return 0;
}
