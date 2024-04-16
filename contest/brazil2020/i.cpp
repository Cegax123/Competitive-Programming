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

const ll mod = (ll) 1e9 + 7;
const int maxn = 1e5 + 5;

ll dp[maxn][2];
vi adj[maxn];

ll ex(ll a, ll b, ll c) {
	ll ans = 1;

	while(b > 0) {
		if(b&1) ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}

	return ans;
}

void dfs(int v) {
    if(adj[v].empty()) {
        dp[v][0] = dp[v][1] = 1;
        return;
    }

    ll nf = 1;
    for(int to : adj[v]) {
        dfs(to);
        nf = nf * dp[to][0] % mod;
    }

    int k = adj[v].size() + 2;
    vector<ll> a(k, 1);

    for(int i = 0; i < (int) adj[v].size(); i++) {
        int u = adj[v][i];
        a[i+1] = dp[u][0];
    }


    ll pre[k], suf[k];

    pre[0] = a[0];

    for(int i = 1; i < k; i++) 
        pre[i] = pre[i-1] * a[i] % mod;

    suf[k-1] = a[k-1];
    
    for(int i = k-2; i >= 0; i--) 
        suf[i] = suf[i+1] * a[i] % mod;

    dp[v][0] = dp[v][1] = 0;

    for(int i = 1; i < k-1; i++) {
        dp[v][1] = (dp[v][1] + pre[i-1] * dp[adj[v][i-1]][1] % mod * suf[i+1] % mod) % mod;
    }

    dp[v][0] = (dp[v][1] + nf) % mod;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;

    for(int i = 1; i < n; i++) {
        int p; cin >> p;
        p--;

        adj[p].pb(i);
    }

    dfs(0);

    cout << dp[0][0] << "\n";
	
    return 0;
}


