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
vector<vi> adj;
vector<bool> vis;
vi tin, low;
int timer;
vector<vector<bool>> isBridge;
vii ans;

void dfs(int v, int p = -1) {
    vis[v] = 1;
    tin[v] = low[v] = timer++;

    for(int to : adj[v]) {
        if(to == p) continue;
        if(vis[to]) {
            low[v] = min(low[v], tin[to]);
        }
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);

            if(low[to] > tin[v]) {
                isBridge[v][to] = isBridge[to][v] = 1;
                ans.pb({v, to});
                ans.pb({to, v});
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    vis.clear(); vis.resize(n, 0);
    tin.clear(); tin.resize(n, -1);
    low.clear(); low.resize(n, -1);
    isBridge.clear(); isBridge.resize(n, vector<bool>(n, 0));
    ans.clear();

    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        dfs(i);
    }
}

void dfs2(int v) {
    vis[v] = 1;   

    for(int to : adj[v]) {
        if(!isBridge[v][to]) {
            ans.pb({v, to});
            isBridge[v][to] = isBridge[to][v] = 1;
        }
        if(!vis[to])
            dfs2(to);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int tc = 1;
    while(cin >> n >> m and (n or m)) {
        adj.clear();
        adj.resize(n);

        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            a--; b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        find_bridges();

        vis.clear(); vis.resize(n, 0);
        dfs2(0);

        cout << tc++ << "\n\n";
        for(auto e : ans) 
            cout << e.first+1 << " " << e.second+1 << "\n";
        
        cout << "#\n";
    }
	
	return 0;
}

