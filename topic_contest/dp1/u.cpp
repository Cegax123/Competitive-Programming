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
	int n; cin >> n;
    ll dp[n+1][3];

    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = 0;

    for(int i = 1; i <= n; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
        dp[i][1] = dp[i-1][0];
        dp[i][2] = dp[i-1][1];
    }

    cout << dp[n][0] << "\n";
	
	return 0;
}

