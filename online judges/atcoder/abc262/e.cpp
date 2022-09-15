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
    int n, m, k; cin >> n >> m >> k;
    int deg[n];
    memset(deg, 0, sizeof(deg));

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;

        deg[u]++;
        deg[v]++;
    }

    int even = 0, odd = 0;
    for(int i = 0; i < n; i++)
        if(deg[i]&1) odd++;

    even = n-odd;
    
    const ll mod = 998244353;
    const int maxn = 2e5+5;
    ll f[maxn+1];
    f[0] = 1;

    for(int i = 1; i <= maxn; i++)
        f[i] = f[i-1] * 1ll * i % mod;

    auto comb = [&] (int a, int b) {
        if(b > a) return 0ll;
        ll num = f[a];
        ll den = f[a-b] * f[b] % mod;

        return num * ex(den, mod-2, mod) % mod;
    };

    ll ans = 0;
    for(int num_odd = 0; num_odd <= k; num_odd += 2) {
        ans += comb(even, k-num_odd) * comb(odd, num_odd) % mod;
        ans %= mod;
    }

    cout << ans << "\n";
	
    return 0;
}


