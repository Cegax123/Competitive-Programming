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

int n, m;
int c[maxn];

struct Edge {
    int to, tp;
};

vector<Edge> adj[maxn];

void coloring(int v, int color = 0) {
    c[v] = color;

    for(Edge& e : adj[v]) {
        int to = e.to;

        if(c[to] == -1) 
            coloring(to, 1-c[v]);
    }
}

bool vis[maxn];

bool check_bipartite(int v) {
    queue<int> q;

    q.push(v);
    vis[v] = 1;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(Edge& e : adj[u]) {
            int to = e.to;

            if(c[to] == c[u]) return 0;

            if(!vis[to]) {
                q.push(to);
                vis[to] = 1;
            }
        }
    }

    return 1;
}

vi g[maxn];
int color[maxn];

bool check_cycle(int v) {
    color[v] = 1;

    for(int to : g[v]) {
        if(color[to] == 0) {
            if(check_cycle(to))
                return 1;
        }
        else if(color[to] == 1)
            return 1;
    }
    color[v] = 2;
    return 0;
}

vi ans;

void toposort(int v) {
    vis[v] = 1;
    for(int to : g[v]) {
        if(vis[to]) continue;
        toposort(to);
    }
    ans.pb(v);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int tp; cin >> tp;
        int u, v; cin >> u >> v;
        u--; v--;
        
        adj[u].pb({v, tp});
        adj[v].pb({u, tp});
    }

    memset(c, -1, sizeof(c));

    for(int i = 0; i < n; i++)
        if(c[i] == -1)
            coloring(i);

    bool cmp = 1;

    for(int i = 0; i < n; i++)
        if(vis[i] == 0)
            cmp &= check_bipartite(i);

    if(cmp == 0) {
        cout << "NO\n";
        return 0;
    }

    for(int i = 0; i < n; i++) {
        for(Edge& e : adj[i]){ 
            int to = e.to, tp = e.tp;

            if(tp == 1 and c[i] == 0) g[i].pb(to);
            if(tp == 2 and c[i] == 1) g[i].pb(to);
        }
    }

    bool cycle = 0;
    for(int i = 0; i < n; i++) {
        if(color[i] == 0)
            cycle |= check_cycle(i);
    }

    if(cycle) {
        cout << "NO\n";
        return 0;
    }

    memset(vis, 0, sizeof(vis));

    for(int i = 0; i < n; i++) {
        if(vis[i] == 0) toposort(i);
    }

    reverse(all(ans));

    int x[n];

    for(int i = 0; i < n; i++)
        x[ans[i]] = i;

    cout << "YES\n";

    for(int i = 0; i < n; i++) {
        cout << (c[i] == 0 ? 'L' : 'R') << " " << x[i] << "\n";
    }

	return 0;
}

