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

const ll INF = (ll) 1e18;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    int a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    if(m == 1) {
        ll local = max(0ll, (ll) a[0]-k);
        ll ans = local;

        for(int i = 1; i < n; i++) {
            local = max(0ll, local+a[i]-k);
            ans = max(ans, local);
        }

        cout << ans << "\n";
        return 0;
    }

    vector<ll> dp(m, -INF);

    dp[0] = 0;
    dp[1] = a[0]-k;

    ll ans = max(dp[0], dp[1]);

    for(int i = 1; i < n; i++) {
        vector<ll> ndp(m, -INF);

        for(int j = 2; j < m; j++) 
            ndp[j] = max(dp[j-1]+a[i], -INF);

        ndp[0] = max(dp[m-1]+a[i], 0ll);
        ndp[1] = max(dp[0]+a[i]-k, (ll) a[i]-k);
        
        dp = ndp;

        for(int i = 0; i < m; i++)
            ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
	
	return 0;
}

