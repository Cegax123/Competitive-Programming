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

struct Edge {
	int u, v;
};

const int maxn = 1e5+5;

vii adj[maxn];
vector<Edge> edges;


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m, q; cin >> n >> m >> q;

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;

		adj[a].pb({b, i});
		adj[b].pb({a, i});
		edges.pb({a, b});
	}
	
	while(q--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		a--; b--; c--; d--;

		
	}
	
	return 0;
}
