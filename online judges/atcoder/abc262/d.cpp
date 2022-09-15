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

const int mod = 998244353;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int a[n+1];

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    int dp[n+1][n+1][n+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; i++)
        dp[0][i][0] = 1;

    for(int i = 1; i <= n; i++) {
        int ndp[n+1][n+1][n+1];
        memset(ndp, 0, sizeof(ndp));

        for(int j = 1; j <= i; j++) {
            for(int c = 1; c <= n; c++) {
                for(int r = 0; r < c; r++) {
                    int br = r-a[i];
                    br %= c;
                    if(br < 0) br += c;

                    ndp[j][c][r] += dp[j-1][c][br];
                }
            }
        }

        for(int j = 1; j <= n; j++)
            for(int c = 1; c <= n; c++)
                for(int r = 0; r <= n; r++)
                    dp[j][c][r] = (dp[j][c][r] + ndp[j][c][r]) % mod;

    }

    int ans = 0;

    for(int i = 1; i <= n; i++) 
        ans = (ans + dp[i][i][0]) % mod;
	
    cout << ans << "\n";
    return 0;
}


