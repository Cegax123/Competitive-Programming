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

const int maxn = 3e5+5;
int n;
int c[maxn], cnt[maxn];
int tot_black;
vi adj[maxn], g[maxn];

void dfs(int v, int p=-1) {
	cnt[v] = c[v];
	
	for(int to : adj[v]) {
		if(to == p) continue;
		dfs(to, v);
		
		cnt[v] += cnt[to];

		if(c[to]) g[to].pb(v);
		else if(cnt[to] >= 2) g[to].pb(v);

		if(c[v]) g[v].pb(to);
		else if(tot_black-cnt[to] >= 2) g[v].pb(to);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	tot_black = 0;

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> c[i];
		tot_black += c[i];
	}

	for(int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs(0);

	vi ans(n, 0);
	queue<int> q;
	
	for(int i = 0; i < n; i++) {
		if(c[i]) {
			q.push(i);
			ans[i] = 1;
		}
	}

	while(!q.empty()) {
		int v = q.front(); q.pop();
		
		for(int to : g[v]) {
			if(ans[to]) continue;

			ans[to] = 1;
			q.push(to);
		}
	}

	for(int i = 0; i < n; i++)
		cout << ans[i] << " ";

	return 0;
}
