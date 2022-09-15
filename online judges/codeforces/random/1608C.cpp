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

struct Player {
	int a, b, id;
};

bool orderA(const Player& p1, const Player& p2) {
	return p1.a > p2.a;
}

bool orderB(const Player& p1, const Player& p2) {
	return p1.b > p2.b;
}

const int maxn = 1e5+5;

vi adj[maxn];
bool vis[maxn];

void dfs(int v) {
	vis[v] = 1;

	for(auto to : adj[v]) {
		if(!vis[to]) dfs(to);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;

		for(int i = 0; i < n; i++) {
			adj[i].clear();
			vis[i] = 0;
		}

		int a[n], b[n];

		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n; i++) cin >> b[i];
		
		vector<Player> p;
		for(int i = 0; i < n; i++)
			p.pb({a[i], b[i], i});

		sort(all(p), orderA);
		int v1 = p[0].id;

		for(int i = 0; i+1 < n; i++) {
			adj[p[i+1].id].pb(p[i].id);
		}

		sort(all(p), orderB);
		int v2 = p[0].id;

		for(int i = 0; i+1 < n; i++) {
			adj[p[i+1].id].pb(p[i].id);
		}

		dfs(v1);
		dfs(v2);

		string ans(n, '0');

		for(int i = 0; i < n; i++) {
			if(vis[i]) ans[i] = '1';
		}

		cout << ans << "\n";
	}
	
	
	return 0;
}
