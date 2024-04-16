#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e3 + 10;

vector<int> adj[maxn];
pair<int, int> h[maxn][3];
int diam[maxn];
pair<int, int> nodes[maxn];

void dfs(int v, int p=-1) {
	h[v][2] = {0, v};
	nodes[v] = {v, v};
	diam[v] = 0;

	for(int to : adj[v]) if(to != p) {
		dfs(to, v);

		h[v][0] = h[to][2];
		h[v][0].first ++;

		sort(h[v], h[v]+3);

		if(diam[to] > diam[v]) {
			diam[v] = diam[to];
			nodes[v] = nodes[to];
		}
	}

	if(h[v][2].first + h[v][1].first > diam[v]) {
		diam[v] = h[v][2].first + h[v][1].first;
		nodes[v] = {h[v][2].second, h[v][1].second};
	}
}

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;

		for(int i = 0; i < n; i++) adj[i].clear();
		for(int i = 0; i < n; i++) h[i][0] = h[i][1] = h[i][2] = {-1, -1};

		for(int i = 0; i < n-1; i++) {
			int u, v; cin >> u >> v;
			u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		dfs(0);

		
	}


	return 0;
}
