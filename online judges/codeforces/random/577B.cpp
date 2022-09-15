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
	int n, m; cin >> n >> m;

	if(n >= m) {
		cout << "YES\n";
		return 0;
	}	

	int a[n];

	for(int i = 0; i < n; i++)
		cin >> a[i];

	bool dp[m];
	memset(dp, 0, sizeof(dp));
	
	dp[a[0]%m] = 1;

	for(int i = 1; i < n; i++) {
		bool tmp[m];
		memset(tmp, 0, sizeof(tmp));
	
		for(int j = 0; j < m; j++) {
			if(dp[j]) tmp[(j+a[i])%m] = 1;
		}

		dp[a[i]%m] = 1;
		for(int j = 0; j < m; j++) {
			dp[j] = dp[j] or tmp[j];
			// cout << dp[j] << " ";
		}
		// cout << "\n";
	}

	cout << (dp[0]?"YES\n":"NO\n");

	return 0;
}