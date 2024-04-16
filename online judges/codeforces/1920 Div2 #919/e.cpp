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

const int maxn = 2500+5;
const int mod = 998244353;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<vector<int>> dp(n+5, vector<int>(n+5));

        for(int i = 1; i <= n; i++) dp[0][i] = 1;

        for(int sum = 1; sum <= n; sum++) {
            for(int x = 1; x <= n; x++) {
                for(int j = 1; j * x <= sum; j++) {
                    if(x+j <= k+1) dp[sum][x] = (dp[sum][x] + dp[sum-j*x][j]) % mod;
                }
            }
        }

        int ans = 0;

        for(int x = 1; x <= n; x++)
            ans = (ans + dp[n][x]) % mod;

        cout << ans << "\n";
    }

	
    return 0;
}


