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

const int maxn = 2500000 + 5;
const ll mod = (ll) 1e9 + 7;

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
    vector<ll> fact(maxn);
    fact[0] = 1;

    for(int i = 1; i < maxn; i++) {
        fact[i] = fact[i-1] * i % mod;
    }

    vector<ll> ifact(maxn);

    ifact[maxn-1] = ex(fact[maxn-1], mod-2, mod);
    for(int i = maxn-2; i >= 0; i--) {
        ifact[i] = ifact[i+1] * (i+1) % mod;
    }

    auto comb = [&](ll x, ll y) {
        return fact[x] * ifact[y] % mod * ifact[x-y] % mod;
    };

    int d; cin >> d;
   
    vector<ll> a(d+1), b(d+1);

    for(int i = 0; i <= d; i++) cin >> a[i];
    for(int i = 0; i <= d; i++) cin >> b[i];

    auto get = [&](const vector<ll>& c, int k) {
        ll ans = 0;
        for(int i = 0; i <= k; i++) {
            ans = ans + comb(k, i) * (i % 2 == 0 ? 1 : -1) * c[k-i] % mod;
            ans %= mod;
        }

        if(ans < 0) ans += mod;
        return ans;
    };

    ll A = get(a, d);
    ll b1 = get(a, d-1);
    ll b2 = get(b, d-1);

    ll ans = (b2-b1) * ex(A, mod-2, mod) % mod;
    if(ans < 0) ans += mod;

    cout << ans << "\n";

    return 0;
}


