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
	int n; cin >> n;

	char board[n+1][n+1];

	for(int i = 0; i < n; i++)
		cin >> board[i];

	int dp[n][n];

	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	if(board[0][0] == '*') dp[0][0] = 0;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(board[i][j] == '*' or (i == 0 && j == 0)) continue;
			if(i) dp[i][j] = (dp[i][j]+dp[i-1][j])%mod;
			if(j) dp[i][j] = (dp[i][j]+dp[i][j-1])%mod;
		}
	}

	cout << dp[n-1][n-1] << "\n";
	
	return 0;
}