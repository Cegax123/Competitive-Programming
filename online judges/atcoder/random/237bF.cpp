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

    const int maxd = 10;
    const int mod = 998244353;

    int dp[maxd+2][maxd+2][maxd+2];
    memset(dp, 0, sizeof(dp));

    dp[m+1][m+1][m+1] = 1;

    for(int i = 0; i < n; i++) {
        int ndp[maxd+2][maxd+2][maxd+2];
        memset(ndp, 0, sizeof(ndp));
        for(int a = 1; a <= m+1; a++) {
            for(int b = 1; b <= m+1; b++) {
                for(int c = 1; c <= m+1; c++) {
                    for(int d = 1; d <= m; d++) {
                        int na = a, nb = b, nc = c;

                        if(d <= a) na = d;
                        else if(d <= b) nb = d;
                        else if(d <= c) nc = d;
                        else continue;

                        ndp[na][nb][nc] = (ndp[na][nb][nc] + dp[a][b][c]) % mod;
                    }
                }
            }
        }

        for(int a = 1; a <= m+1; a++) {
            for(int b = 1; b <= m+1; b++) {
                for(int c = 1; c <= m+1; c++) {
                    dp[a][b][c] = ndp[a][b][c];
                }
            }
        }
    }

    ll ans = 0;

    for(int a = 1; a <= m; a++) {
        for(int b = 1; b <= m; b++) {
            for(int c = 1; c <= m; c++) {
                ans = (ans + dp[a][b][c]) % mod;
            }
        }
    }
    
    cout << ans << "\n";
	
    return 0;
}


