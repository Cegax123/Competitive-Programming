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

bool isP(int x) {
    if(x <= 1) return false;
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0) return false;
    return true;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, s, t; cin >> n >> m >> s >> t;
    s--; t--;
    vi adj[n];

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    bool vis[n][2];
    memset(vis, 0, sizeof(vis));

    int d[n][2];
    memset(d, -1, sizeof(d));

    queue<ii> q;
    q.push({s, 0});

    vis[s][0] = 1;
    d[s][0] = 0;

    while(!q.empty()) {
        ii u = q.front(); q.pop();

        int v = u.first, pty = u.second;

        int npty = 1 ^ pty;

        for(int to : adj[v]) if(!vis[to][npty]) {
            d[to][npty] = d[v][pty] + 1;
            vis[to][npty] = 1;
            q.push({to, npty});
        }
    }

    int ans = 1e9;

    if(d[t][0] == 2) {
        ans = min(ans, 2);
    }
    if(d[t][1] != -1) {
        int x = d[t][1];

        while(!isP(x)) {
            x += 2;
        }

        ans = min(ans, x);
    }

    cout << (ans == 1e9 ? -1 : ans) << "\n";
	
    return 0;
}


