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
    int a[n+1];
    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a+1, a+n+1);

    const int mod = 998244353;

    int dp[n+1][k+1];
    int sum[n+1][k+1];

    int ans = 0;

    for(int x = 1; x * (k-1) <= a[n]; x++) {
        memset(dp, 0, sizeof(dp));
        memset(sum, 0, sizeof(sum));

        dp[0][0] = 1;
        sum[0][0] = 1;

        int r[n+1];

        for(int i = 1; i <= n; i++) {
            int L = 1, R = i;
            while(L < R) {
                int m = (L+R+1) >> 1;
                if(a[i]-a[m] >= x) L = m;
                else R = m-1;
            }
            if(a[i]-a[L] < x) L = R = 0;
            r[i] = L;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= min(i, k); j++) {
                dp[i][j] = sum[r[i]][j-1];
            }

            for(int j = 0; j <= min(i, k); j++)
                sum[i][j] = (sum[i-1][j] + dp[i][j]) % mod;
        }

        //for(int i = 1; i <= n; i++) {
            //for(int j = 1; j <= n; j++)
                //cout << dp[i][j] << " ";
            //cout << "\n";
        //}

        //cout << endl;

        ans = (ans + sum[n][k]) % mod;
    }

    cout << ans << "\n";
	
    return 0;
}


