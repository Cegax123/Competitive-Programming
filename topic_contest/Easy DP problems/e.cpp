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
    const int maxn = 105;
    int dp[maxn][2];

    const int mod = 1e9 + 7;

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    int n, k, d; cin >> n >> k >> d;
    int ans = 0;

    for(int h = 1; h <= n; h++) {
        int ndp[maxn][2];
        memset(ndp, 0, sizeof(ndp));

        for(int i = 1; i <= k; i++) {
            for(int j = 0; j <= n; j++) {
                if(j + i > n) continue;
                for(int st = 0; st < 2; st++) {
                    int nxt_st = (i >= d ? 1 : st);

                    ndp[j + i][nxt_st] = (ndp[j + i][nxt_st] + dp[j][st]) % mod;

                    //if(j + i == n and nxt_st == 1 and h == 1) {
                        //cout << i << " " << j << " " << st << " " << dp[j][st] << endl;
                    //}
                }
            }
        }

        for(int i = 0; i < maxn; i++) {
            for(int j = 0; j < 2; j++)
                dp[i][j] = ndp[i][j];
        }

        //cout << dp[n][1] << endl;

        ans = (ans + dp[n][1]) % mod;
    }
	
    cout << ans << "\n";
    

    return 0;
}


