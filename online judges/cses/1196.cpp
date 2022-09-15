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

int n, m, k;

const int maxk = 10;
const int maxn = 1e5+5;
const ll INF = (ll) 1e18;

vii adj[maxn];
bool vis[maxn][maxk];
ll d[maxn][maxk];

void init() {
	memset(vis, 0, sizeof(vis));

	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxk; j++)
			d[i][j] = INF;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;

	init();

	for(int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		a--; b--;

		adj[a].pb({b,c});
	}

	priority_queue<pair<ll,ii>, vector<pair<ll, ii>>, greater<pair<ll, ii> > > pq;
	pq.push({0, {0,0}});

	d[0][0] = 0;

	while(!pq.empty()) {
		auto v = pq.top(); pq.pop();

		int s = v.second.first, t = v.second.second;

		if(vis[s][t]) 
			continue;

		vis[s][t] = 1;

		for(auto e : adj[s]) {
			int to = e.first;
			ll w = e.second;

			int ind = k;

			for(int i = 0; i < k; i++) {
				if(!vis[to][i]) {
					ind = i;
					break;
				}
			}

			if(ind == k) continue;

			for(int i = ind; i < k; i++) {
				if(d[s][t] + w < d[to][i]) {

					for(int j = k-1; j > i; j--) {
						if(d[to][j-1] < d[to][j]) {
							d[to][j] = d[to][j-1];
							pq.push({d[to][j],{to,j}});
						}
					}

					d[to][i] = d[s][t] + w;

					pq.push({d[to][i],{to,i}});
					break;
				}
			}
		}
	}

	for(int i = 0; i < k; i++)
		cout << d[n-1][i] << " ";

	return 0;
}