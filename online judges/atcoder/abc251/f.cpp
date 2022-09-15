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

vi adj[maxn];
bool vis[maxn];
vii a, b;

void dfs(int v) {
    vis[v] = 1;
    for(int to : adj[v]) {
        if(vis[to]) continue;
        dfs(to);
        a.pb({to, v});
    }
}

void bfs(int src) {
    memset(vis, 0, sizeof(vis));
    
    queue<int> q;
    q.push(src);
    vis[src] = 1;

    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(int to : adj[v]) { 
            if(vis[to]) continue;
            q.push(to);
            b.pb({v, to});
            vis[to] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1);

    for(int i = 0; i < n-1; i++)
        cout << a[i].first << " " << a[i].second << "\n";

    bfs(1);

    for(int i = 0; i < n-1; i++)
        cout << b[i].first << " " << b[i].second << "\n";

    return 0;
}


