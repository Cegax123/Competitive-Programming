#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;
const int maxs = maxn * maxn * maxn;

int dp[maxn][maxs];

int main() {
	int n, k, m; cin >> n >> k >> m;

	dp[0][0] = 1;

	int s = 0;

	for(int i = 1; i <= n; i++) {
		s += i;
		for(int j = 0; j <= s * k; j++) {
			dp[i][j] = dp[i-1][j];
			if(j >= i) dp[i][j] = (dp[i][j] + dp[i][j-i]) % m;
			if(j - i * (k+1) >= 0) {
				dp[i][j] -= dp[i-1][j - i * (k+1)];
				dp[i][j] %= m;
				if(dp[i][j] < 0) dp[i][j] += m;
			}
		}
	}

	s = 0;

	for(int i = 1; i <= n; i++) {
		int ans = 0;
		s += i;

		for(int j = 0; j <= s * k; j++) {
			ans = (ans + dp[i-1][j] * 1ll * dp[n-i][j] % m) % m;
		}

		ans = ans * 1ll * (k+1) % m - 1;
		ans %= m;
		if(ans < 0) ans += m;

		cout << ans << "\n";
	}

	return 0;
}
