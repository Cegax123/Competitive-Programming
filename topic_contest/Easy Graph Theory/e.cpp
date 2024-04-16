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



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
    int g[n][n];
    memset(g, 0, sizeof(g));

    int deg[n];
    memset(deg, 0, sizeof(deg));

    vii edges;

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        edges.pb({u, v});

        g[u][v] = g[v][u] = 1;
        deg[u]++; deg[v]++;
    }

    int ans = 1e9;

    for(auto& e : edges) {
        int u = e.first, v = e.second;

        for(int i = 0; i < n; i++) {
            if(i == u or i == v) continue;
            if(g[i][u] == 0 or g[i][v] == 0) continue;
            
            int cnt = deg[i] + deg[u] + deg[v] - 6;
            ans = min(ans, cnt);
        }
    }

    cout << (ans == 1e9 ? -1 : ans) << "\n";
	
    return 0;
}


