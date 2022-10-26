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

const int maxn = 3e5+5;

struct Edge {
	int u, v;
};

vector<Edge> edges;
vii adj[maxn]; // adjacency list of graph
int tin[maxn], low[maxn];
bool vis[maxn], isBridge[maxn], hasArtifact[maxn];

int timer;
int n, m, a, b;

void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    for (auto e : adj[v]) {
        int to = e.first, id = e.second;
        if (to == p) continue;
        if (vis[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
            	isBridge[id] = 1;
        }
    }
}

// BUILD TREE

vi idv;
vi cnt;

void assign_id(int v, int ind) {
    idv[v] = ind;
    for(auto e : adj[v]) {
        int to = e.first, id = e.second;
        if(idv[to] != -1 or isBridge[id]) continue;

        assign_id(to, ind);
    }
}

void build_tree() {
    idv.clear(); idv.resize(n, -1);
    
    int ind = 0;
    for(int i = 0; i < n; i++) {
        if(idv[i] == -1) {
            assign_id(i, ind);
            ind++;
        }
    }

    cnt.clear(); cnt.resize(ind, 0);

    for(int i = 0; i < m; i++) {
        int x = edges[i].u, y = edges[i].v;

        if(idv[x] == idv[y])
        	cnt[idv[x]] += hasArtifact[i];
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;

	for(int i = 0; i < m; i++) {
		int u, v, z; cin >> u >> v >> z;
		u--; v--;

		adj[u].pb({v, i});
		adj[v].pb({u, i});

		edges.pb({u, v});

		hasArtifact[i] = z;
	}

	cin >> a >> b;
	a--; b--;

	int st = 0;
	for(auto e : adj[a]) {
		if(e.first == b) {
			if(hasArtifact[e.second]) st = 2;
			else st = 1;
		}
	}

	if(st == 2) {
		cout << "YES\n";
		return 0;
	}

	if(st == 0 and a != b) {
		adj[a].pb({b, m});
		adj[b].pb({a, m});
		hasArtifact[m] = 0;
		edges.pb({a, b});
		m++;
	}

	dfs(0, -1);
	build_tree();

	if(cnt[idv[a]]+cnt[idv[b]]) cout << "YES\n";
	else cout << "NO\n";
	
	return 0;
}
