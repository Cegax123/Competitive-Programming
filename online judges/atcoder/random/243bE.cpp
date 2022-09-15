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

struct Edge {
    int u, v, w;
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
    
    vector<Edge> edges;
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;

        edges.pb({u, v, w});
    }

    const int maxn = 305;
    const ll INF = (ll) 1e18;
    ll d[maxn][maxn];

    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn; j++)
            d[i][j] = INF;

    for(Edge& e : edges) {
        d[e.u][e.v] = d[e.v][e.u] = e.w;
    }

    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    int ans = 0;
    for(Edge& e : edges) {
        bool to_erase = false;

        for(int i = 0; i < n; i++)
            if(d[e.u][i] + d[i][e.v] <= e.w)
                to_erase = 1;

        ans += to_erase;
    }

    cout << ans << "\n";
	
    return 0;
}


