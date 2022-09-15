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
const int maxn = 2e5+5;
ll p2[maxn];

ll ex(ll a, ll b, ll c) {
	ll ans = 1;

	while(b > 0) {
		if(b&1) ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}

	return ans;
}

void init() {
	p2[0] = 1;
	for(int i = 1; i < maxn; i++) {
		p2[i] = 2ll*p2[i-1]%mod;
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	init();

	int t; cin >> t;
	
	while(t--) {
		ll n, x; cin >> n >> x;

		ll row = 1;
		ll curr = 1;

		for(ll k = 2; k < n; k += 2) {
			curr = curr * (n-k+2ll) % mod;
			curr = curr * (n-k+1ll) % mod;

			curr = curr * ex(k, mod-2, mod) % mod;
			curr = curr * ex(k-1, mod-2, mod) % mod;

			row += curr;
			row %= mod;

			// cout << curr << "\n";
		}

		if(n&1) {
			row++;
			row %= mod;
		}

		// cout << row << endl;

		ll prow[maxn];
		prow[0] = 1;

		for(int i = 1; i < maxn; i++) 
			prow[i] = row * prow[i-1] % mod;

		ll ans = prow[x];
		
		if((n&1) == 0) {	
			for(int i = 0; i < x; i++) {
				ans += prow[i] * ex(2ll, (x-1-i)*n, mod);
				ans %= mod;
			}
		}

		cout << ans << "\n";
	}
	
	return 0;
}