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

const int maxn = 5e5 + 5;

vi adj[maxn];

int c[maxn], dp[maxn], sz[maxn];

void dfs(int v, int p) {
    sz[v] = 1;

    for(int to : adj[v]) { 
        if(to == p) continue;
        dfs(to, v);

        sz[v] += sz[to];
    }
}

bool cmp(int i, int j) {
    return 2 * sz[i] - dp[i] < 2 * sz[j] - dp[j];
}

void solve(int v, int p) {
    vi ch;

    for(int to : adj[v]) { 
        if(to == p) continue;
        solve(to, v);

        ch.pb(to);
    }

    sort(all(ch), cmp);

    dp[v] = c[v];
    int curr = 1;

    for(int i : ch) {
        dp[v] = max(dp[v], curr + dp[i]);
        curr += 2 * sz[i];
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;
    
    for(int i = 0; i < n; i++) 
        cin >> c[i];

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;

        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    dfs(0, 0);
    solve(0, 0);

    // for(int i = 0; i < n; i++)
    //     cout << dp[i] << " ";
    //
    // cout << endl;

    dp[0] = max(dp[0], c[0] + 2 * n - 2);
	
    cout << dp[0] << "\n";

    return 0;
}


