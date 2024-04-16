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

const int maxn = (int) 1e6 + 5;
int sieve[maxn];
ll f[maxn], ivf[maxn];

const ll mod = 998244353;

ll ex(ll a, ll b, ll c) {
	ll ans = 1;

	while(b > 0) {
		if(b&1) ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    sieve[1] = 0;
    for(int i = 2; i < maxn; i++) {
        if(sieve[i]) continue;
        sieve[i] = i;
        for(int j = 2; i * j < maxn; j++) {
            if(!sieve[i * j]) sieve[i * j] = i;
        }
    }

    f[0] = 1;

    for(int i = 1; i < maxn; i++)
        f[i] = f[i-1] * i % mod;

    ivf[maxn-1] = ex(f[maxn-1], mod-2, mod);

    for(int i = maxn-2; i >= 0; i--) {
        ivf[i] = ivf[i+1] * (i+1) % mod;
    }

    int n; cin >> n;
    int a[2 * n];


    map<int, int> cnt;

    for(int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    vi np, p;

    for(auto e : cnt) {
        if(sieve[e.first] == e.first) {
            p.pb(e.second);
        }
        else np.pb(e.second);
    }

    int k = p.size();
    if(k < n) {
        cout << 0 << "\n";
        return 0;
    }

    ll dp[k][n];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = p[0];

    for(int i = 1; i < k; i++) {
        dp[i][0] = p[i];

        for(int j = 1; j <= i; j++)
            dp[i][j] = (dp[i-1][j-1] * p[i]) % mod;

        for(int j = 0; j <= i; j++)
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
    }

    ll ans = dp[k-1][n-1] * f[n] % mod;

    for(int x : np) {
        ans = ans * ivf[x] % mod;
    }

    for(int x : p) {
        ans = ans * ivf[x] % mod;
    }

    cout << ans << "\n";

    return 0;
}


