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
	int c[n];

	for(int i = 0; i < n; i++)
		cin >> c[i];

	int dp[x+1];

	memset(dp, -1, sizeof(dp));
	dp[0] = 0;

	for(int t = 1; t <= x; t++) {
		for(int i = 0; i < n; i++) {
			if(t-c[i] >= 0 and dp[t-c[i]] != -1) {
				if(dp[t] == -1) dp[t] = dp[t-c[i]]+1;
				else dp[t] = min(dp[t], dp[t-c[i]]+1);
			}
		}
	}

	cout << dp[x] << "\n";
	
	return 0;
}