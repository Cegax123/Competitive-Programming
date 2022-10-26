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

#define eb emplace_back
#define trav(i, x) for (auto i : x)
#define sz(x) (int)x.size()
#define set_to(x, v) fill(all(x), v)

const int inf = 1e9;
struct Dinic {
	struct Edge {
		int to, cap, flow, link;
		Edge() {}
		Edge(int to, int cap, int link, int flow=0):
			to(to), cap(cap), link(link), flow(flow) {}
	};
	vector<vector<Edge>> g;
	vi d, pt;
	
	Dinic(int n): g(n), d(n), pt(n) {}

	void addEdge(int a, int b, int cap) {
		if (a == b) return;
	  	int pa = sz(g[a]), pb = sz(g[b]);
		g[a].eb(b, cap, pb); g[b].eb(a, 0, pa);
	}

	bool bfs(int src, int snk) {
		queue<int> q({src});
		set_to(d, inf);
		d[src] = 0;
		while (!q.empty()) {
			int v = q.front(); q.pop();
			if (v == snk) return true;
			trav(e, g[v]) {
				if (e.flow >= e.cap) continue;
				if (d[e.to] > d[v] + 1) {
					d[e.to] = d[v] + 1;
					q.emplace(e.to);
				}
			}
		}
		return false;
	}

	int dfs(int x, int snk, int flow=inf) {
		if (x == snk || !flow) return flow;
		for (; pt[x] < sz(g[x]); ++pt[x]) {
			auto& e = g[x][pt[x]];
			if (d[e.to] == d[x] + 1) {
				int res = min(e.cap - e.flow, flow);
				if (int push = dfs(e.to, snk, res)) {
					e.flow += push;
					g[e.to][e.link].flow -= push;
					return push;
				}
			}
		}
		return 0;
	}

	ll solve(int s, int t) {
		ll res = 0;
		while (bfs(s, t)) {
			set_to(pt, 0);
			while (int flow = dfs(s, t)) {
				res += flow;
			}
		}
		return res;
	}
};


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
    int a[n];

	for(int i = 0; i < n; i++) cin >> a[i];

    vi adj[n];

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    set<int> s;
    
    for(int j = 0; j < n; j++) {
        int tmp = a[j];

        for(int i = 2; i <= (int) 3e4; i++) {
            if(tmp % i) continue;
			
            s.insert(i);
            while(tmp % i == 0) tmp /= i;
        }

		if(tmp > 1) s.insert(tmp);
    }

    int ans = 0;
    for(int x : s) {
        Dinic dinic(2 * n + 2);

        for(int i = 0; i < n; i++) {
			int tmp = a[i];
			int cap = 0;

			while(tmp % x == 0) {
				cap++;
				tmp /= x;
			}

            if(i&1) dinic.addEdge(i, n + 1, cap);
			else dinic.addEdge(n, i, cap);
        }

        for(int i = 0; i < n; i++) {
			if(i&1) continue;
            for(int to : adj[i]) {
				dinic.addEdge(i, to, inf);
            }
        }

        int cnt = dinic.solve(n, n + 1);
		ans += cnt;
    }

    cout << ans << "\n";
	
    return 0;
}


