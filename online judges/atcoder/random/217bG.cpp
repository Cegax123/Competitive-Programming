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
    ll n, m; cin >> n >> m;
    const ll mod = (ll) 998244353;

    const int maxn = 5005;

    ll fact[maxn], ifact[maxn];

    fact[0] = 1;
    for(int i = 1; i < maxn; i++)
        fact[i] = fact[i-1] * i % mod;

    ifact[maxn-1] = ex(fact[maxn-1], mod-2, mod);

    for(int i = maxn-2; i >= 0; i--) 
        ifact[i] = ifact[i+1] * (i+1) % mod;

    auto perm = [&](int x, int y) {
        if(x < y) return 0ll;
        assert(x-y >= 0);
        return fact[x] * ifact[x-y] % mod;
    };

    ll f[n+1];
    memset(f, 0, sizeof(f));

    int cnt[m];
    memset(cnt, 0, sizeof(cnt));

    for(int i = 1; i <= n; i++)
        cnt[i%m]++;

    for(int i = 1; i <= n; i++) {
        ll x = 1;

        for(int j = 0; j < m; j++) {
            x = x * perm(i, cnt[j]) % mod;
        }

        ll y = 0;

        for(int j = 1; j < i; j++)
            y = (y + (perm(i, j) * f[j])) % mod;

        x = (x-y)%mod;
        if(x < 0) x += mod;

        f[i] = x * ifact[i] % mod;

        cout << f[i] << "\n";
    }

	
    return 0;
}


