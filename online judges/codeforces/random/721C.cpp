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

const int maxn = 5005;
const int INF = 1e9+7;

vector<vi> ans(maxn, vi(maxn, INF));
vector<vi> p(maxn, vi(maxn, -1));

vii adj[maxn];
int in[maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m, t;
	cin >> n >> m >> t;

	for(int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;

		u--; v--;

		adj[u].pb({v, w});
		in[v]++;
	}

	queue<int> to_del;

	for(int i = 1; i < n; i++)
		if(in[i] == 0) to_del.push(i);

	while(!to_del.empty()) {
		int v = to_del.front(); to_del.pop();

		for(auto edge : adj[v]) {
			int to = edge.first;
			in[to]--;

			if(in[to] == 0 and to) to_del.push(to);
		}
	}
	
	queue<int> q;
	q.push(0);

	ans[0][1] = 0;

	while(!q.empty()) {
		int v = q.front(); q.pop();
		
		for(auto edge : adj[v]) {
			int to = edge.first, w = edge.second;

			in[to]--;
			if(in[to] == 0) q.push(to);

			for(int i = 0; i <= n; i++) {
				if(ans[v][i] == INF) continue;

				if(ans[v][i] + w < INF and ans[v][i] + w < ans[to][i+1]) {
					ans[to][i+1] = ans[v][i] + w;
					p[to][i+1] = v;
				}
			}
		}
	}

	vi ans_path;

	for(int i = n; i >= 0; i--) {
		if(ans[n-1][i] <= t) {
			ans_path.pb(n);

			int curr = n-1, k = i;

			while(curr) {
				curr = p[curr][k];
				ans_path.pb(curr+1);
				k--;
			}

			break;
		}
	}

	reverse(all(ans_path));
	cout << ans_path.size() << "\n";
	for(int x : ans_path)
		cout << x << " ";
	
	return 0;
}

