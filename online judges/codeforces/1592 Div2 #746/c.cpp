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
int a[maxn];
vi adj[maxn];
int xt[maxn];

void dfs(int u, int p) {
    xt[u] = a[u];

    for(int to : adj[u]) {
        if(to == p) continue;
        dfs(to, u);
        xt[u] ^= xt[to];
    }
}

int cnt;
int X;
int val[maxn];

int dfs2(int u, int p) {

    val[u] = a[u];
    for(int to : adj[u]) {
        if(to == p) continue;
        val[u] ^= dfs2(to, u);

    }

    if(val[u] == X) {
        cnt++;
        val[u] = 0;
    }

    return val[u];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;

        for(int i = 0; i < n; i++) cin >> a[i];

        for(int i = 0; i < n; i++) {
            adj[i].clear();
            xt[i] = 0;
        }

        for(int i = 0; i < n-1; i++) {
            int u, v; cin >> u >> v;
            u--; v--;

            adj[u].pb(v);
            adj[v].pb(u);
        }

        dfs(0, -1);

        if(xt[0] == 0) {
            cout << "YES\n";
            continue;
        }

        X = xt[0];
        
        if(k >= 3) {
            cnt = 0;
            dfs2(0, -1);

            //cout << "HOLA\n";
            //cout << cnt <<endl;
            if(cnt >= 3) cout << "YES\n";
            else cout << "NO\n";
        }
        else cout << "NO\n";
    }

	
    return 0;
}


