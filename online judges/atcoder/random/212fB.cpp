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
const int LOGN = 20;

int n, m, q;

struct Edge {
	int a, b, s, t, id;
};

bool compare_edge(Edge& a, Edge& b) {
	return a.s < b.s;
}

vector<Edge> adj[maxn];
vector<Edge> edges;

int find_next(int c, int x) {
	if(adj[c].empty()) return -1;
	int l = 0, r = adj[c].size()-1;

	while(l < r) {
		int tm = (l+r) >> 1;
		if(x <= adj[c][tm].s) r = tm;
		else l = tm+1;
	}

	if(adj[c][l].s >= x) return adj[c][l].id;
	return -1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;
	
	for(int i = 0; i < m; i++) {
		int a, b, s, t; cin >> a >> b >> s >> t;
		a--; b--;

		adj[a].pb({a, b, s, t, i});
		edges.pb({a, b, s, t, i});
	}

	for(int i = 0; i < n; i++)
		sort(all(adj[i]), compare_edge);

	ii go[m][LOGN];

	for(int i = 0; i < n; i++) {
		for(const Edge& e : adj[i]) {
			go[e.id][0] = {e.b, e.t};
		}
	}

	for(int j = 1; j < LOGN; j++) {
		for(int i = 0; i < n; i++) {
			for(const Edge& e : adj[i]) {
				auto tmp = go[e.id][j-1];
				int c = tmp.first, x = tmp.second;

				int ind = find_next(c, x);

				if(ind == -1) {
					go[e.id][j] = go[e.id][j-1];
				}
				else {
					go[e.id][j] = go[ind][j-1];
				}
			}
		}
	}

	while(q--) {
		int x, y, z; cin >> x >> y >> z;
		y--;

		int ind = find_next(y, x);

		if(ind == -1) {
			cout << y+1 << "\n";
			continue;
		}

		int c = y;
		int t = x;

		for(int j = LOGN-1; j >= 0; j--) {
			if(go[ind][j].second < z) {
				c = go[ind][j].first;
				t = go[ind][j].second;

				ind = find_next(c, t);

				if(ind == -1)
					break;
			}
		}

		if(ind == -1) {
			cout << c+1 << "\n";
			continue;
		}
		if(edges[ind].s >= z)
			cout << c+1 << "\n";
		else 
			cout << edges[ind].a+1 << " " << edges[ind].b+1 << "\n";
	}
	
    return 0;
}
