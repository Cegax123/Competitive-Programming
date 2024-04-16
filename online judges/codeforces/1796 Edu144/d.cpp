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
    int t; cin >> t;
    while(t--) {
        int n, q; cin >> n >> q;
        ll x; cin >> x;

        ll a[n+1];

        for(int i = 1; i <= n; i++)
            cin >> a[i];

        ll dp[n+1][q+1];
        dp[0][0] = 0ll;

        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int k = 0; k <= min(i, q); k++) {
                dp[i][k] = 0ll;
                if(k <= i-1) {
                    dp[i][k] = max(dp[i][k], a[i] - x);
                    dp[i][k] = max(dp[i][k], dp[i-1][k] + a[i] - x);
                }
                if(k) {
                    dp[i][k] = max(dp[i][k], a[i] + x);
                    dp[i][k] = max(dp[i][k], a[i] + x + dp[i-1][k-1]);
                }

                if(n-i >= q-k) ans = max(ans, dp[i][k]);
            }
        }

        cout << ans << "\n";
    }

	
    return 0;
}



