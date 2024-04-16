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
    ll a[n+1];
    for(int i = 1; i <= n; i++) cin >> a[i];

    const int LOG5 = 30;

    vector<vi> dp(n+1, vi(n * LOG5, -1));
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++) {
        int num5 = 0;
        while(a[i] % 5 == 0) {
            a[i] /= 5;
            num5++;
        }

        int num2 = 0;
        while(a[i] % 2 == 0) {
            a[i] /= 2;
            num2++;
        }

        vector<vi> ndp = dp;

        for(int j = 0; j <= i; j++) {
            for(int k = num5; k < LOG5 * n; k++) {
                ndp[j][k] = dp[j][k];
                if(j > 0 and dp[j-1][k-num5] != -1)
                    ndp[j][k] = max(ndp[j][k], num2 + dp[j-1][k-num5]);
            }
        }

        dp = ndp;
    }

    int ans = 0;

    for(int i = 0; i < LOG5 * n; i++)
        ans = max(ans, min(i, dp[k][i]));

    cout << ans << "\n";

    return 0;
}


