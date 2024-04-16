#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3+5;

int parent[maxn], sz[maxn];

void make_set(int v) {
	parent[v] = v;
	sz[v] = 1;
}

int find(int v) {
	if(parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}

void union_sets(int u, int v) {
	u = find(u);
	v = find(v);
	if(u!=v) {
		if(sz[u] < sz[v]) swap(u, v);
		parent[v] = u;
		sz[u] += sz[v];
	}
}

struct Edge {
	int u, v, w;
	bool operator<(const Edge& o) {
		return w < o.w;
	}
};

int main() {
	int n; cin >> n;
	int q[n];
	for(int i = 0; i < n; i++) cin >> q[i];

	for(int i = 0; i < n; i++) make_set(i);

	int m; cin >> m;
	vector<Edge> edges;
	for(int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		u--; v--;

		edges.push_back({u, v, w});
	}

	vector<bool> has_parent(n, 0);

	sort(edges.begin(), edges.end());

	int cost = 0;
	int num = 0;
	for(int i = 0; i < m; i++) {
		int u = edges[i].u, v = edges[i].v, w = edges[i].w;

		if(has_parent[v]) continue;

		int pu = find(u);
		int pv = find(v);

		if(pu != pv) {
			has_parent[v] = 1;
			cost += w;

			union_sets(pu, pv);
			num++;
		}
	}

	if(num != n-1) cout << -1 << "\n";
	else cout << cost << "\n";


	return 0;
}
