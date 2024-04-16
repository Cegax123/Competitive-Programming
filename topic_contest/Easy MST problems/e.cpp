#include<bits/stdc++.h>
using namespace std;

struct Edge {
	int u, v, w;
};

const int maxn = 5e5 + 5;
vector<pair<int, int>> by_w[maxn];
int fiapp[maxn];

bool vis[maxn];

int main() {
	memset(fiapp, -1, sizeof(fiapp));

	int n, m; cin >> n >> m;
	vector<Edge> edges;
	for(int i = 0; i < m; i++) {
		int a, b, w; cin >> a >> b >> w;
		a--; b--;
		edges.push_back({a, b, w});
		by_w[w].push_back({a, b});
	}
	
	for(int i = 0; i < maxn; i++) {
		for(auto e : by_w[i]) {
			if(fiapp[e.first] == -1) fiapp[e.first] = i;
			if(fiapp[e.second] == -1) fiapp[e.second] = i;
		}
	}

	int q; cin >> q;
	while(q--) {
		int k; cin >> k;
		vector<int> v(k);
		for(int i = 0; i < k; i++) cin >> v[i];
		sort(v.begin(), v.end(), [&](int i, int j) {
				return edges[i].w < edges[j].w;
				});

		bool cmp = 1;

		for(int i = 0; i < k; i++) {
			int u = edges[v[i]].u, t = edges[v[i]].v;
			int w = edges[v[i]].w;

			if(!(fiapp[u] == w and fiapp[t] == w)) {
				cmp = 0;
			}
			else {
				vis[u] = vis[t] = 1;
			}
		}

		cout << (cmp ? "YES\n" : "NO\n");

		for(int i = 0; i < k; i++) {
			int u = edges[v[i]].u, t = edges[v[i]].v;
			vis[u] = 0; vis[t] = 0;
		}
	}

	return 0;
}
