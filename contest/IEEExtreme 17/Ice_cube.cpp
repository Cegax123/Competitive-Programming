#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1005;
const int maxk = 21;
int g[maxn][maxn];
int dp[maxn][maxn][maxk];

int main() {
    int t; cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        int n, m, k, b; cin >> n >> m >> k >> b;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> g[i][j];
            }
        }

        memset(dp, -1, sizeof(dp));

        dp[0][0][g[0][0] < b] = g[0][0];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 and j == 0) continue;
                if(g[i][j] < b) {
                    if(i) {
                        for(int r = 1; r < k; r++) {
                            if(dp[i-1][j][r-1] != -1)
                                dp[i][j][r] = max(dp[i][j][r], dp[i-1][j][r-1] + g[i][j]);
                        }
                    }
                    if(j) {
                        for(int r = 1; r < k; r++) {
                            if(dp[i][j-1][r-1] != -1)
                                dp[i][j][r] = max(dp[i][j][r], dp[i][j-1][r-1] + g[i][j]);
                        }
                    }
                }
                else {
                    if(i) {
                        for(int r = 0; r < k; r++) {
                            if(dp[i-1][j][r] != -1) 
                                dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][r] + g[i][j]);
                        }
                    }
                    if(j) {
                        for(int r = 0; r < k; r++) {
                            if(dp[i][j-1][r] != -1)
                                dp[i][j][0] = max(dp[i][j][0], dp[i][j-1][r] + g[i][j]);
                        }
                    }
                }
            }
        }

        int ans = -1;

        for(int r = 0; r < k; r++) {
            ans = max(ans, dp[n-1][m-1][r]);
        }

        cout << "Case " << tt << ": ";
        if(ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << "\n";
        
    }

    return 0;
}
