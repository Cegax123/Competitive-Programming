#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;
vector<int> adj[maxn];
int a[maxn];
int cnt[maxn][2];

ll ans = 0;

void dfs(int v, int p, int h, int j) {
	int d = (a[v] >> j)&1;
	h ^= d;

	for(int to : adj[v]) if(to != p) {
		dfs(to, v, h, j);
		int target = 1 ^ d;

		ans += cnt[to][0] * 1ll * cnt[v][target ^ 0] * (1 << j);
		ans += cnt[to][1] * 1ll * cnt[v][target ^ 1] * (1 << j);

		cnt[v][0] += cnt[to][0];
		cnt[v][1] += cnt[to][1];
	}

	cnt[v][h]++;

	ans += cnt[v][1^h^d] * 1ll * (1 << j);
}

int main() {
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];

	for(int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i = 0; i < 20; i++) {
		memset(cnt, 0, sizeof(cnt));
		dfs(0, 0, 0, i);
	}

	cout << ans << "\n";

	return 0;
}
