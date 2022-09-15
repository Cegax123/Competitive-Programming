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

const int maxn = 2e5+5;
const int LOGN = 20;

int n, m;
int parent[maxn], sz[maxn];

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

struct Edge {
    int u, v, weight, id, used = 0;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<Edge> edges;

vii adj[maxn];
int timer = 0; 
int tin[maxn], tout[maxn];
int up[maxn][LOGN+1];
int max_edge[maxn][LOGN+1];
int h[maxn];

void dfs(int v, int p) {
	if(v == 0) h[v] = 0;
	else h[v] = h[p]+1;

    tin[v] = ++timer;
    up[v][0] = p;

    for(int i = 1; i <= LOGN; i++) 
        up[v][i] = up[up[v][i-1]][i-1];

   	for(int i = 1; i <= LOGN; i++) 
   		max_edge[v][i] = max(max_edge[v][i-1], max_edge[up[v][i-1]][i-1]);

    for(auto e : adj[v]) {
    	int to = e.first, w = e.second;
        if(to == p) continue;

        max_edge[to][0] = w;
        dfs(to, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = LOGN; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;

	for(int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		u--; v--;

		edges.pb({u, v, w, i});
	}
	
	sort(all(edges));

	vector<Edge> result;

	ll cost = 0;
	for(int i = 0; i < n; i++)
		make_set(i);

	for(Edge &e : edges) {
		if(find_set(e.u) != find_set(e.v)) {
			cost += e.weight;
			union_sets(e.u, e.v);
			result.pb(e);
			e.used = 1;
		}
	}

	for(Edge e : result) {
		adj[e.u].pb({e.v, e.weight});
		adj[e.v].pb({e.u, e.weight});
	}

	dfs(0, 0);
	ll ans[m];

	for(Edge e : edges) {
		if(e.used) {
			ans[e.id] = cost;
		}
		else {
			int u = e.u, v = e.v, w = e.weight;

			int p = lca(u, v);
			int k1 = h[u]-h[p], k2 = h[v]-h[p];
			int max1 = 0, max2 = 0;
			int curr = 0;

			assert((k1!=0 ) or (k2!=0));

			for(int j = LOGN; j >= 0; j--) {
				if((k1 >> j)&1) {
					max1 = max(max1, max_edge[u][j]);
					u = up[u][j];
				}
				if((k2 >> j)&1) {
					max2 = max(max2, max_edge[v][j]);
					v = up[v][j];
				}
			}

			// assert(max1 != 0 or max2 != 0);

			curr = max(max1, max2);

			ans[e.id] = cost-curr + w;

		}
	}

	for(int i = 0; i < m; i++)
		cout << ans[i] << "\n";
	
	return 0;
}

