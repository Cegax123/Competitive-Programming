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

const int maxn = 1e4+5;
const int maxk = 10+5;
const int maxl = 100+5;
const int INF = 1e9;

int a[maxl];
vi adj[maxn];

int d[2*maxk][2*maxk];
int dp[1 << (21)];

void st() {
	for(int i = 0; i < 2*maxk; i++)
		for(int j = 0; j < 2*maxk; j++)
			d[i][j] = INF;

	memset(dp, -1, sizeof(dp));
}

int find(int mask, int x) {
	if(mask == 0) return 0;
	if(dp[mask] != -1) return dp[mask];

	// cout << mask << endl;

	for(int i = 0; i < x; i++) {
		for(int j = 0; j < x; j++) {
			if(i == j) continue;
			if(((mask >> i)&1) and ((mask >> j)&1)) {
				int next_mask = mask;
				next_mask ^= (1 << i);
				next_mask ^= (1 << j);

				int v = find(next_mask, x);

				if(dp[mask] == -1) dp[mask] = min(INF, v + d[i][j]);
				else dp[mask] = min(dp[mask], v+d[i][j]); 
			}
		}
	}

	return dp[mask];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	st();
	int n, k, l; cin >> n >> k >> l;
	vi arr(n+1, 0);

	for(int i = 0; i < k; i++) {
		int x; cin >> x;
		arr[x] = 1;	
	}

	vi c;

	c.pb(arr[1]);

	for(int i = 2; i <= n; i++) {
		c.pb(abs(arr[i]-arr[i-1]));
	}

	c.pb(arr[n]);

	vi pos;

	for(int i = 0; i < l; i++)
		cin >> a[i];

	for(int i = 0; i <= n; i++) {
		if(c[i]) pos.pb(i);
		for(int j = 0; j < l; j++) {
			if(i + a[j] <= n) {
				adj[i].pb(i+a[j]);
				adj[i+a[j]].pb(i);
			}
		}
	}

	int x = (int) pos.size();

	for(int i = 0; i < x; i++) {
		bool used[n+1];
		memset(used, 0, sizeof(used));

		vi dis(n+1, INF);

		queue<int> q;
		q.push(pos[i]);

		used[pos[i]] = 1;
		dis[pos[i]] = 0;

		while(!q.empty()) {
			int v = q.front(); q.pop();

			for(int to : adj[v]) {
				if(!used[to]) {
					q.push(to);
					dis[to] = dis[v] + 1;
					used[to] = 1;
				}
			}
		}

		for(int j = 0; j < x; j++) {
			if(i != j) {
				d[i][j] = dis[pos[j]];
			}
		}
	}

	int init = 0;

	for(int i = 0; i < x; i++)
		init |= (1 << i);

	int ans = find(init, x);

	if(ans >= INF) cout << "-1\n";
	else cout << ans << "\n";

	return 0;
}
