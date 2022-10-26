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

int n, m;
vi tin, low;
int timer;
vector<bool> vis, isArticulation;
vector<vi> adj;

void init() {
    adj.clear(); adj.resize(n);
    vis.clear(); vis.resize(n, false);
    isArticulation.clear(); isArticulation.resize(n, false);
    tin.clear(); tin.resize(n, -1);
    low.clear(); low.resize(n, -1);

    timer = 0;
}

void dfs(int v, int p = -1) {
    vis[v] = 1;
    tin[v] = low[v] = timer++;
    int children = 0;

    for(int to : adj[v]) {
        if(to == p) continue;
        if(vis[to]) {
            low[v] = min(low[v], tin[to]);
        }
        else {
            children++;
            dfs(to, v);

            low[v] = min(low[v], low[to]);

            if(low[to] >= tin[v] and p != -1) 
                isArticulation[v] = 1;
        }
    }

    if(p == -1 and children > 1) 
        isArticulation[v] = 1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        cin >> n >> m;

        init();

        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            a--; b--;

            adj[a].pb(b);
            adj[b].pb(a);
        }

        for(int i = 0; i < n; i++)
            if(!vis[i]) dfs(i, -1);

        int ans = 0;
        for(int i = 0; i < n; i++)
            ans += isArticulation[i];

        cout << "Case " << tc << ": ";
        cout << ans << "\n";
    }
	
	
	return 0;
}

