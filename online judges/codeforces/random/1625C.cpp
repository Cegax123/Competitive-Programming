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
    int n, l, k; cin >> n >> l >> k;
    int d[n+1], a[n+1];

    for(int i = 0; i < n; i++) 
        cin >> d[i];
	
    for(int i = 0; i < n; i++)
        cin >> a[i];

    d[n] = l;
    a[n] = 0;
    
    int dp[n+1][n+1][2];

    memset(dp, -1, sizeof(dp));

    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i][i][0] = dp[i-1][i-1][0] + a[i-1] * (d[i]-d[i-1]);
    }

    if(k == 0) {
        cout << dp[n][n][0] << "\n";
        return 0;
    }

    int ans = 2e9;

    for(int j = 1; j <= k; j++) {
        int x = j&1;
        for(int pos = 1; pos <= n; pos++) {
            for(int rem = 0; rem < pos; rem++) {
                if(dp[pos-1][rem][x] != -1) {
                    if(dp[pos][pos][x] == -1) dp[pos][pos][x] = dp[pos-1][rem][x] + a[rem] * (d[pos]-d[rem]);
                    dp[pos][pos][x] = min(dp[pos][pos][x], dp[pos-1][rem][x] + a[rem] * (d[pos]-d[rem]));
                    if(pos == n) ans = min(ans, dp[pos][pos][x]);
                }

                if(dp[pos-1][rem][1-x] != -1 and pos < n) {
                    if(dp[pos][rem][x] == -1) dp[pos][rem][x] = dp[pos-1][rem][1-x];
                    dp[pos][rem][x] = min(dp[pos][rem][x], dp[pos-1][rem][1-x]);
                }
            }
        }
    }

    // for(int i = 0; i <= n; i++) {
    //     for(int j = 0; j <= i; j++) {
    //         for(int x = 0; x <= k; x++) {
    //             cout << i << " " << j << " " << x << " " << dp[i][j][x] << endl;
    //         }
    //     }
    // }


    cout << ans << "\n";

	return 0;
}

