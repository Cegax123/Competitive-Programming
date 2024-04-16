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

    const int maxs = 1305;
    const int off = 1305;

    const ll INF = (ll) 1e18;
    vector<vector<ll>> dp(2 * maxs + 10, vector<ll> (k+1, -INF));

    dp[off][0] = 0;

    for(int i = 0; i < n; i++) {
        int v, t; cin >> v >> t;

        vector<vector<ll>> ndp = dp;

        for(int j = -maxs; j < maxs; j++) {
            for(int u = 0; u <= k; u++) {
                if(j + t <= maxs) ndp[j + off][u] = max(ndp[j + off][u], dp[j + t + off][u] + v);
                if(j - t >= -maxs) ndp[j + off][u] = max(ndp[j + off][u], dp[j - t + off][u] + v);

                if(u) {
                    if(j + 2 * t <= maxs) ndp[j + off][u] = max(ndp[j + off][u], dp[j + 2 * t + off][u-1] + v);
                    if(j - 2 * t >= -maxs) ndp[j + off][u] = max(ndp[j + off][u], dp[j - 2 * t + off][u-1] + v);
                }
            }
        }

        dp = ndp;
    }

    ll ans = 0;

    for(int i = 0; i <= k; i++)
        ans = max(ans, dp[off][i]);

    cout << ans << "\n";
	
    return 0;
}


