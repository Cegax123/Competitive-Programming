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

const int maxn = 4005;
const int mod = 998244353;
vi adj[maxn];

vi dp[maxn][2];
int sz[maxn];

void predfs(int v, int p) {
    sz[v] = 1;

    for(int to : adj[v]) if(to != p) {
        predfs(to, v);
        sz[v] += sz[to];
    }
}

void dfs(int v, int p) {
    dp[v][0].resize(sz[v]/2+5, 0);
    dp[v][1].resize(sz[v]/2+5, 0);

    dp[v][0][0] = 1;

    for(int to : adj[v]) if(to != p) {
        dfs(to, v);

        for(int k = sz[v]/2+2; k >= 0; k--) {
            for(int j = 0; j <= sz[to]/2+2; j++) {
                if(k-j >= 0 and j) {
                    //if(v == 0 and k == 1) {
                        //cout << to << " " << j << endl;
                        //cout << dp[to][0][j] << " " << dp[v][0][k-j] << endl;
                    //}
                    dp[v][0][k] += ((dp[to][1][j] + dp[to][0][j])) * 1ll * dp[v][0][k-j] % mod;
                    dp[v][0][k] %= mod;
                }

                if(k-j-1 >= 0) {
                    dp[v][1][k] += dp[to][0][j] * 1ll * dp[v][0][k-j-1] % mod;
                    dp[v][1][k] %= mod;
                }

                if(k - j >= 0 and j) {
                    dp[v][1][k] += ((dp[to][0][j] + dp[to][1][j])) * 1ll * dp[v][1][k-j] % mod;
                    dp[v][1][k] %= mod;
                }
            }
        }
    }
}

int f[maxn];
int ivf[maxn], iv2[maxn];

int ex(int a, int b, int c) {
    int ans = 1;
    while(b) {
        if(b&1) ans = ans * 1ll * a % c;
        a = a * 1ll * a % c;
        b >>= 1;
    }

    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    f[0] = 1;
    for(int i = 1; i < maxn; i++) {
        f[i] = f[i-1] * 1ll * i % mod;
    }

    ivf[maxn-1] = ex(f[maxn-1], mod-2, mod);

    for(int i = maxn-2; i >= 0; i--) {
        ivf[i] = ivf[i+1] * 1ll * (i+1) % mod;
    }

    iv2[0] = 1;
    int curr = ex(2, mod-2, mod);

    for(int i = 1; i < maxn; i++) {
        iv2[i] = iv2[i-1] * 1ll * curr % mod;
    }

    auto g = [&](int n) {
        return f[2 * n] * 1ll * ivf[n] % mod * iv2[n] % mod;
    };

    int n; cin >> n;
    for(int i = 0; i < 2 * n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    predfs(0, 0);
    dfs(0, 0);

    int ans = g(n);
    for(int k = 1; k <= n; k++) {
        int op = (dp[0][0][k] + dp[0][1][k]) % mod;
        if(k&1) {
            ans -= op * 1ll * g(n-k) % mod;
            ans %= mod;
            if(ans < 0) ans += mod;
        }
        else {
            ans += op * 1ll * g(n-k) % mod;
            ans %= mod;
        }
    }

    cout << ans << "\n";

    return 0;
}


