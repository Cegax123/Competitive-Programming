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


const ll mod = 1e9 + 7;
const int maxn = 3e5+10;

ll fact[maxn];

ll f(ll r, ll c) {
	ll num = fact[r + c];
	ll den = fact[r] * fact[c] % mod;
	return num * ex(den, mod-2, mod) % mod;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k; cin >> n >> k;

	if(k > n) {
		ll ans = 1;
		for(int i = 0; i < n; i++)
			ans = ans * 2 % mod;

		cout << ans << "\n";
		return 0;
	}

	fact[0] = 1;
	for(int i = 1; i < maxn; i++) fact[i] = fact[i-1] * i % mod;

	ll ans = 1;
	for(int i = 1; i <= k; i++) {
		ans += f(n-i, i);
		ans %= mod;
	}
	
	cout << ans << "\n";
    return 0;
}


