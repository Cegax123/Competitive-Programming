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
const ll INF = (ll) 1e18;

vii adj[maxn];
ll d[maxn][2];
bool vis[maxn][2];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m; cin >> n >> m;

	for(int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		a--; b--;
		adj[a].pb({b,c});
	}

	for(int i = 0; i < maxn; i++)
		d[i][0] = d[i][1] = INF;

	d[0][0] = d[0][1] = 0;

	memset(vis, 0, sizeof(vis));

	priority_queue<pair<ll, ii>, vector<pair<ll, ii> >, greater<pair<ll, ii> > > pq;
	pq.push({0, {0, 0}});

	while(!pq.empty()) {
		auto v = pq.top(); pq.pop();

		int s = v.second.first, tp = v.second.second;

		if(vis[s][tp]) 
			continue;

		vis[s][tp] = 1;

		for(auto e : adj[s]) {
			int to = e.first; ll w = e.second;

			if(tp == 0 and !vis[to][1]) {
				if(d[s][tp] + w/2 < d[to][1]) {
					d[to][1] = d[s][tp] + w/2;
					pq.push({d[to][1],{to, 1}});
				}
			}

			if(!vis[to][tp]) {
				if(d[s][tp] + w < d[to][tp]) {
					d[to][tp] = d[s][tp] + w;
					pq.push({d[to][tp],{to, tp}});
				}
			}
		}
	}	

	cout << min(d[n-1][0], d[n-1][1]) << "\n";
	
	return 0;
}