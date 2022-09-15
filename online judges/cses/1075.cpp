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
    ll dp[n+5][n+5][3][3];
    memset(dp, 0, sizeof(dp));
    dp[1][1][0][2] = 1;

    const ll mod = 1e9+7;

    auto add = [&] (ll a, ll b) {
        return (a+b)%mod;
    };

    auto mul = [&] (ll a, ll b) {
        return a * b % mod;
    };

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            for(int mid = 0; mid <= 2; mid++) {
                for(int se = 0; se <= 2; se++) {
                    dp[i+1][j+1][2][0] = add(dp[i+1][j+1][2][0], mul(dp[i][j][mid][se], j-1));
                    dp[i+1][j+1][1][1] = add(dp[i+1][j+1][1][1], mul(dp[i][j][mid][se], 2));

                    dp[i+1][j-1][0][0] = add(dp[i+1][j-1][0][0], mul(dp[i][j][mid][se], max(j-1-mid, 0)));

                    dp[i+1][j][1][0] = add(dp[i+1][j][1][0], mul(dp[i][j][mid][se], max(2*j-2-mid, 0)));
                    dp[i+1][j][0][1] = add(dp[i+1][j][0][1], mul(dp[i][j][mid][se], max(2-se, 0)));
                }
            }
        }
    }

    //for(int i = 1; i <= 3; i++) {
        //for(int j = 1; j <= i; j++) {
            //for(int mid = 0; mid <= 2; mid++) {
                //for(int se = 0; se <= 2; se++) {
                    //cout << i << " " << j << " " << mid << " " << se << " " << dp[i][j][mid][se] << endl;
                //}
            //}
        //}
    //}

    ll ans = 0;

    for(int mid = 0; mid <= 2; mid++) {
        for(int se = 0; se <= 2; se++) {
            ans = add(ans, dp[n][1][mid][se]);
        }
    }

    cout << ans << "\n";
	
    return 0;
}


