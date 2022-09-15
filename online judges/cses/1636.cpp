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
	int n, x; cin >> n >> x;
	int a[n];

	for(int i = 0; i < n; i++)
		cin >> a[i];

	int dp[x+1];

	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	for(int i = 0; i < n; i++) {
		for(int t = 1; t <= x; t++) {
			if(t-a[i] >= 0) {
				dp[t] = (dp[t] + dp[t-a[i]]) % mod;
			}
		}
	}

	cout << dp[x] << "\n";
	
	return 0;
}
