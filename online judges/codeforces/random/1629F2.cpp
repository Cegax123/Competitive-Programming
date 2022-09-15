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

const ll mod = 1e9+7;
const int maxn = 1e6;

ll p2[maxn+5];
ll fact[maxn+5];

ll ex(ll a, ll b, ll c) {
	ll ans = 1;

	while(b > 0) {
		if(b&1) ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}

	return ans;
}

ll mul(ll a, ll b, ll c) {
	return a*b%c;
}

ll comb(ll a, ll b, ll c) {
	if(a < 0 || a-b < 0) return 0ll;

	ll div = mul(fact[b], fact[a-b], mod);
	return mul(fact[a], ex(div, mod-2, mod), mod);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	p2[0] = 1;
	fact[0] = 1;

	for(int i = 1; i <= maxn; i++) {
		p2[i] = mul(p2[i-1], 2, mod);
		fact[i] = mul(fact[i-1], i, mod);
	}

	int t; cin >> t;
	while(t--) {
		ll n, m, k; cin >> n >> m >> k;
		
		if(n == m) {
			cout << mul(n, k, mod) << "\n";
			continue;
		}

		ll ans = 0;

		for(int i = 1; i <= m; i++) {
			ll sum = mul(comb(n-i-1, m-i, mod), i, mod);
			sum = mul(sum, ex(p2[n-i], mod-2, mod), mod);
			ans = (ans+sum)%mod;
		}

		ans = mul(ans, k, mod);

		cout << ans << "\n";
	}
	
	return 0;
}

