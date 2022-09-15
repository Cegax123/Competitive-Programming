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



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, x; cin >> n >> x;
	int h[n], s[n];

	for(int i = 0; i < n; i++)
		cin >> h[i];
	
	for(int i = 0; i < n; i++)
		cin >> s[i];

	int dp[n+1][x+1];

	memset(dp, 0, sizeof(dp));

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= x; j++) {
			dp[i][j] = dp[i-1][j];
			if(j-h[i-1] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-h[i-1]]+s[i-1]);
		}
	}

	cout << dp[n][x];

	return 0;
}