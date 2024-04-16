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
const int mod = 998244353;
vi adj[maxn];

int ans[maxn];
int sz[maxn];
int f[maxn];

void dfs(int v, int p) {
    sz[v] = 1;
    ans[v] = 1;

    int cnt = 0;

    for(int to : adj[v]) {
        if(to == p) continue;
        dfs(to, v);

        ans[v] = ans[v] * 1ll * ans[to] % mod;
        sz[v] += sz[to];
        if(sz[to] & 1) cnt++;
    }

    ans[v] = ans[v] * 1ll * f[cnt] % mod;

}

ll ex(ll a, ll b, ll c) {
    ll ans = 1;
    while(b) {
        if(b&1) ans = ans * a % c;
        a = a * a % c;
        b >>= 1;
    }

    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    f[0] = 1;

    for(int i = 1; i < maxn; i++) {
        if(i&1) {
            f[i] = f[i-1] * 1ll * i % mod;
        }
        else {
            ll prod = (i * 1ll * (i-1) / 2) % mod;
            f[i] = prod * f[i-2] % mod;
            f[i] = f[i] * 1ll * ex(i/2, mod-2, mod) % mod;
        }
    }



    int n; cin >> n;
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(0, 0);

    cout << ans[0] << "\n";
	
    return 0;
}


