#include<bits/stdc++.h>
using namespace std;

const int maxn = 5005;
int dp[maxn][maxn];
int sz[maxn];
vector<int> adj[maxn];

const int mod = 1e9 + 7;

void dfs(int v, int p) {
	dp[v][1] = 1;
	sz[v] = 1;

	for(int to : adj[v]) if(to != p) {
		dfs(to, v);

		vector<int> ndp(sz[v] + sz[to] + 5, 0);

		for(int i = 1; i <= sz[v]; i++) {
			for(int j = 1; j <= sz[to]; j++) {
				ndp[i+j] = (ndp[i+j] + dp[v][i] * 1ll * dp[to][j] % mod) % mod;
				if(i > 0 and j > 0) ndp[i+j-2] = (ndp[i+j-2] + dp[v][i] * 1ll * dp[to][j] % mod * i % mod * j % mod) % mod;
			}
		}

		for(int i = 0; i <= sz[v] + sz[to]; i++)
			dp[v][i] = ndp[i];

		if(v == 0) {
			for(int i = 0; i <= sz[v] + sz[to]; i++) {
				cout << dp[v][i] << " ";
			}
			cout << endl;
		}

		sz[v] += sz[to];
	}
}

int main() {
	int n; cin >> n;
	for(int i = 0; i < n-1; i++) {
		int x, y; cin >> x >> y;
		x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs(0, 0);

	//int v = 1;
	//for(int i = 0; i <= sz[v]; i++)
		//cout << dp[v][i] << " ";
	//cout << endl;


	cout << dp[0][0] << "\n";

	return 0;
}
