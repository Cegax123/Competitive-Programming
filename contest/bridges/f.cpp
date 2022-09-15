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
typedef unsigned long long ull;
//cout << setprecision(12) << fixed;

const int maxn = 1e4+5;

int n, m;
int tin[maxn], low[maxn];
vector<bool> vis, is_articulation;
vector<vi> adj;
int timer;
ull ans;

void init() {
	timer = 0;
	ans = 1;

	vis.clear(); vis.resize(n, 0);
	is_articulation.clear(); is_articulation.resize(n, 0);
	adj.clear(); adj.resize(n);
}

void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (vis[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
				is_articulation[v] = true;
            ++children;
        }
    }
    if(p == -1 && children > 1)
		is_articulation[v] = true;
}

set<int> s;

void dfs2(int v, ull& sz) {
	sz++;
	vis[v] = 1;

	for(int to : adj[v]) {
		if(vis[to]) continue;
		if(is_articulation[to]) {
			s.insert(to);
			continue;
		}
		dfs2(to, sz);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	for(int tc = 1; tc <= t; tc++) {
		cin >> n >> m;
		
		init();

		for(int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}

		for(int i = 0; i < n; i++) {
			if(vis[i] == 0)
				dfs(i);
		}

		vis.clear(); vis.resize(n);

		int cnt = 0;
		for(int i = 0; i < n; i++) {
			if(is_articulation[i] or vis[i]) continue;

			s.clear();

			ull sz = 0;
			dfs2(i, sz);

			if((int) s.size() <= 1) {
				ans *= sz;
				cnt++;
			}
		}

		if(cnt == 1) {
			cnt = 2;
			ans = (ull) (n * (n-1)) / 2ull;
		}

		cout << "Case " << tc << ": ";
		cout << cnt << " " << ans << "\n";
	}
	
	
	return 0;
}

