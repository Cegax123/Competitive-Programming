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

const int maxn = 1e5 + 5;

vector<vi> adj, cc;
vi curr;

bool vis[maxn];
int h[maxn];
set<ii> used_edges;

void dfs(int v, int p) {
    vis[v] = 1;
    curr.pb(v);

    for(int to : adj[v]) {
        if(to == p or vis[to]) continue;
        used_edges.insert({min(v, to), max(v, to)});
        h[to] = h[v]+1;
        dfs(to, v);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
    
    if(n <= 3) {
        cout << -1 << "\n";
        return 0;
    }

    adj.resize(n);

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, -1);
            cc.pb(curr);
            curr.clear();
        }
    }

    bool even_cycle = false, odd_cycle = false;
    for(int i = 0; i < n; i++) {
        for(int to : adj[i]) {
            int x = min(i, to), y = max(i, to);
            if(used_edges.count({x, y})) continue;
            int sum = h[x] + h[y];

            if(sum&1) even_cycle = 1;
            else odd_cycle = 1;
        }
    }

    if(even_cycle and odd_cycle) {
        cout << 0 << "\n";
        return 0;
    }

    int mxG = 0;
    int cnt2 = 0;

    for(const auto& v : cc) {
        mxG = max(mxG, (int) v.size());
        cnt2 += (int) v.size() == 2;
    }


    if(even_cycle) {
        if(mxG == 1) cout << 3 << "\n";
        else if(mxG == 2) cout << 2 << "\n";
        else cout << 1 << "\n";
        return 0;
    }
    
    if(odd_cycle) {
        if(mxG == 1) cout << 4 << "\n";
        else if(mxG == 2) {
            if(cnt2 == 1) cout << 3 << "\n";
            else cout << 2 << "\n";
        }
        else cout << 
    }

    return 0;
}


