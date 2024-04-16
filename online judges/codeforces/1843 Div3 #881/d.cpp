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

const int maxn = 2e5 + 5;

vector<vi> adj;
int val[maxn];

void dfs(int v, int p) {
    int child = 0;

    for(int to : adj[v]) {
        if(to == p) continue;
        dfs(to, v);
        child++;
        val[v] += val[to];
    }

    val[v] += child == 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        adj.clear(); adj.resize(n);
        for(int i = 0; i < n; i++) val[i] = 0;
        for(int i = 0; i < n-1; i++) {
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        dfs(0, 0);

        int q; cin >> q;
        while(q--) {
            int x, y; cin >> x >> y;
            x--; y--;

            cout << val[x] * 1ll * val[y] << "\n";
        }
    }

	
    return 0;
}


