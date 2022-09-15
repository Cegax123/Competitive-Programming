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

const int maxn = 505;
const ll INF = (ll) 1e15;

vector<vector<ll> > dis(maxn, vector<ll>(maxn, INF));

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m, q; cin >> n >> m >> q;

	for(int i = 0; i < n; i++)
		dis[i][i] = 0;

	for(int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		a--; b--;

		dis[a][b] = min(dis[a][b], (ll) c);
		dis[b][a] = dis[a][b];
	}

	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
			}
		}
	}

	while(q--) {
		int a, b; cin >> a >> b;
		a--; b--;

		cout << (dis[a][b] == INF ? -1:dis[a][b]) << "\n";
	}
	
	return 0;
}