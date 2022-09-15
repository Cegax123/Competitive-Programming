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

ll sum(ll a, ll b, ll c) {
	ll ans = (a+b)%mod;
	ans = (ans+mod)%mod;
	return ans;
}

ll mul(ll a, ll b, ll c) {
	ll ans = (a*b)%c;
	ans = (ans+mod)%mod;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		
		vi a(n);
		ll ans = 0;

		int cnt[n+1];
		memset(cnt, 0, sizeof(cnt));

		for(int i = 0; i < n; i++) {
			cin >> a[i];
			cnt[a[i]]++;
			if(a[i] == 1) ans++;
		}
		
		ans = ex(2, ans, mod);
		ans = sum(ans, -1, mod);

		ll dp[n+1];
		memset(dp, 0, sizeof(dp));

		for(int i = 0; i < n; i++) {
			cnt[a[i]]--;
			if(a[i] >= 2) {
				ans += mul(dp[a[i]-2], ex(2, cnt[a[i]] + cnt[a[i]-2], mod), mod);
			}
			if(a[i] == 0) {
				dp[0] = mul(2, dp[0], mod);
				dp[0] = sum(dp[0], 1, mod);
			}
			else {
				dp[a[i]] = mul(2, dp[a[i]], mod);
				dp[a[i]] = sum(dp[a[i]], dp[a[i]-1], mod);
			}
		}

		for(int i = 0; i <= n; i++) {
			ans = sum(ans, dp[i], mod);
		}

		cout << ans << "\n";
	}
	
	
	return 0;
}
