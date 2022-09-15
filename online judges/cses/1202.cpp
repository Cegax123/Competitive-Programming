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

const int maxn = 1e5+5;
const int mod = 1e9+7;
const ll INF = (ll) 1e18;

vector<vector<pair<ll,int> > > adj(maxn);
vector<ll> dist(maxn, INF);
int numw[maxn], minw[maxn], maxw[maxn];
bool vis[maxn];



void dijkstra(int s = 0) {
	memset(numw, 0, sizeof(numw));
	memset(minw, 0, sizeof(minw));
	memset(maxw, 0, sizeof(maxw));
	memset(vis, 0, sizeof(vis));

	priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;

	numw[s] = 1;
	dist[s] = 0;

	pq.push({dist[s], s});

	while(!pq.empty()) {
		int v = pq.top().second; pq.pop();

		if(vis[v]) continue;

		vis[v] = 1;

		for(auto e : adj[v]) {
			int to = e.first;
			ll w = e.second;

			if(dist[v] + w < dist[to]) {
				dist[to] = dist[v]+w;

				numw[to] = numw[v];
				minw[to] = minw[v]+1;
				maxw[to] = maxw[v]+1;

				pq.push({dist[to], to});
			}
			else if(dist[v]+w == dist[to]) {
				numw[to] = (numw[to]+numw[v])%mod;
				minw[to] = min(minw[to], minw[v]+1);
				maxw[to] = max(maxw[to], maxw[v]+1);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m; cin >> n >> m;

	while(m--) {
		int a,b,c; cin >> a >> b >> c;
		a--; b--;
		adj[a].pb({b,c});
	}

	dijkstra();

	// for(int i = 0; i < n; i++) 
	// 	cout << dist[i] << " " << numw[i] << " " << minw[i] << " " << maxw[i] << "\n";

	cout << dist[n-1] << " " << numw[n-1] << " " << minw[n-1] << " " << maxw[n-1] << "\n";
	
	return 0;
}