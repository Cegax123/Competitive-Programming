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

vi adj[maxn];
bool vis[maxn];
int parent[maxn];
int vst, vend;

bool dfs(int v, int p) {
    vis[v] = 1;

    for(int to : adj[v]) {
        if(to == p) continue;

        if(vis[to]) {
            vend = v;
            vst = to;
            return 1;
        }
        parent[to] = v;
        if(dfs(to, v)) 
            return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m; cin >> n >> m;
	
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vst = -1;

    for(int i = 1; i <= n; i++) {
        if(vis[i] == 0 and dfs(i, -1)) 
            break;
    }

    if(vst == -1) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        vi cycle;

        cycle.pb(vst);
        for(int v = vend; v != vst; v = parent[v]) 
            cycle.pb(v);

        cycle.pb(vst);

        cout << cycle.size() << "\n";

        for(int v : cycle)
            cout << v << " ";

        cout << "\n";
    }
	
	return 0;
}

