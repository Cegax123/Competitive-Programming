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
    int n, k; cin >> n >> k;
    vi cnt(k+1, 0);

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        cnt[a]++;
    }

    int dp[k+1][3][3][3];
    memset(dp, -1, sizeof(dp));

    dp[0][0][0][0] = 0;
    int ans = 0;

    for(int i = 1; i <= k; i++) {
        for(int l = 0; l < 3; l++) {
            for(int m = 0; m < 3; m++) {
                for(int r = 0; r < 3; r++) {
                    if(l + m + r > cnt[i]) continue;

                    for(int b = 0; b < 3; b++) {
                        if(dp[i-1][m][r][b] == -1) continue;
                        dp[i][l][m][r] = max(dp[i][l][m][r], dp[i-1][m][r][b] + r + (cnt[i]-l-m-r) / 3);
                    }

                    //cout << i << " " << l << " " << m << " " << r << " " << dp[i][l][m][r] << "\n";

                    ans = max(ans, dp[i][l][m][r]);
                }
            }
        }
    }

    cout << ans << "\n";
	
    return 0;
}


