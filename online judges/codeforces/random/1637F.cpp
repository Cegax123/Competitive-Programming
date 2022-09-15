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

int n;
vi adj[maxn];
int h[maxn];
int deg[maxn];

ll ans = 0;

void dfs(int v, int p, int need=0) {
    if(deg[v] == 1) {
        ans += max(need, h[v]);
        return;
    }

    for(int to : adj[v]) {
        if(to == p) continue;
        dfs(to, v, max(need, h[v]));
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> h[i];

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;

        adj[u].pb(v);
        adj[v].pb(u);

        deg[u]++;
        deg[v]++;
    }
	
    bool lin = 1;

    for(int i = 0; i < n; i++) 
        if(deg[i] > 2) lin = 0;

    if(lin) {
        int mx = 0;

        for(int i = 0; i < n; i++)
            mx = max(mx, h[i]);

        cout << 2 * mx << "\n";
        return 0;
    }

    int src = 0;

    for(int i = 0; i < n; i++) 
        if(deg[i] > 1) src = i;

    dfs(src, -1);

    cout << src << endl;
    cout << ans << "\n";
	
	return 0;
}

