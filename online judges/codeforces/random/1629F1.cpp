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

const ll mod = 1e9+7;

ll sum(ll a, ll b, ll c) {
	ll ans = (a+b)%c;
	return (ans+c)%c;
}

ll mul(ll a, ll b, ll c) {
	return a*b%c;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t; cin >> t;
	while(t--) {
		int n, m, k; cin >> n >> m >> k;

		int dp[n+1][n+1];

		for(int i = 0; i <= n; i++) {
			dp[i][0] = 0;
			dp[i][i] = mul(i, k, mod);
		}

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j < i; j++) {
				dp[i][j] = mul(ex(2, mod-2, mod), sum(dp[i-1][j], dp[i-1][j-1], mod), mod);
			}
		}

		cout << dp[n][m] << "\n";
	}
	
	return 0;
}
