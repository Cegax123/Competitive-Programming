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

const int mod = 1e9+7;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m; cin >> n >> m;
	int x[n];

	for(int i = 0; i < n; i++)
		cin >> x[i];

	int dp[n][m+2];

	memset(dp, 0, sizeof(dp));

	if(x[0]) dp[0][x[0]] = 1;
	else {
		for(int i = 1; i <= m; i++)
			dp[0][i] = 1;
	}

	for(int i = 0; i < n-1; i++) {
		for(int j = 1; j <= m; j++) {
			if(x[i+1] == 0) {
				dp[i+1][j-1] = (dp[i+1][j-1]+dp[i][j])%mod;
				dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod;
				dp[i+1][j+1] = (dp[i+1][j+1]+dp[i][j])%mod;
			}
			else {
				if(abs(x[i+1]-j) <= 1) {
					dp[i+1][x[i+1]] = (dp[i+1][x[i+1]]+dp[i][j]) % mod;
				}
			}
		}
	}

	int ans = 0;

	for(int j = 1; j <= m; j++)
		ans = (ans+dp[n-1][j])%mod;

	cout << ans << "\n";
	
	return 0;
}
