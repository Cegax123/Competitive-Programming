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

const int maxn = 2e5+5;

vi adj[maxn];
int dp[maxn];
int sum_child[maxn];

void dfs(int v, int p = -1) {
	for(int to : adj[v]) {
		if(to == p) continue;
		dfs(to, v);

		sum_child[v] += dp[to];
	}

	dp[v] = sum_child[v];

	for(int to : adj[v]) {
		if(to == p) continue;

		dp[v] = max(dp[v], sum_child[v]-dp[to]+sum_child[to]+1);
	}
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;

	for(int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	dfs(0);

	cout << dp[0] << "\n";
	
    return 0;
}
