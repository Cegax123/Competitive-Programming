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

const int maxn = 1e4+5;
const int maxm = 1e5+5;

struct Edge {
    int a, b;
};

vector<Edge> edges;

int n, m; 
int tin[maxn], low[maxn];
int timer = 0;
vector<vii> adj(maxn);
bool vis[maxn], is_bridge[maxm];

void dfs(int v, int p) {
    vis[v] = 1;
    tin[v] = low[v] = timer++;

    for(auto e : adj[v]) {
        int to = e.first, id = e.second;
        if(to == p) continue;
        if(vis[to]) {
            low[v] = min(low[v], tin[to]);
        }
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);

            if(low[to] > tin[v]) {
                is_bridge[id] = 1;
            }
        }
    }
}

int idv[maxn];

void assign_id(int v, int ind) {
    idv[v] = ind;

    for(auto e : adj[v]) {
        int to = e.first, id = e.second;
        if(idv[to] != -1 or is_bridge[id]) continue;
        assign_id(to, ind);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ifstream in;
    ofstream out;

    in.open("bridges.in");
    out.open("bridges.out");

	memset(idv, -1, sizeof(idv));
    
    in >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b; in >> a >> b;
        a--; b--;

        adj[a].pb({b, i});
        adj[b].pb({a, i});
        edges.pb({a, b});
    }

    dfs(0, -1);

    int ind = 0;
    for(int i = 0; i < n; i++) {
        if(idv[i] == -1) {
            assign_id(i, ind);
            ind++;
        }
    }

    vi ans;
    for(int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b;
        if(is_bridge[i] and idv[a] != idv[b]) {
            ans.pb(i+1);
        }
    }

    out << ans.size() << "\n";

    for(int x : ans)
        out << x << " ";
	
	return 0;
}
