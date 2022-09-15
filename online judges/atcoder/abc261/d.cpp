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
    int n, m; cin >> n >> m;
    ll x[n+1];
    for(int i = 1; i <= n; i++)
        cin >> x[i];

    ll add[n+1];
    memset(add, 0, sizeof(add));

    for(int i = 0; i < m; i++) {
        int c, y; cin >> c >> y;
        add[c] = y;
    }

    vector<ll> dp(n + 1, -INF);

    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        vector<ll> ndp(n + 1, -INF);
        for(int j = 0; j <= n; j++) {
            ndp[0] = max(ndp[0], dp[j]);
        }
        for(int j = 1; j <= n; j++) {
            ndp[j] = max(ndp[j], dp[j-1] + add[j] + x[i]);
        }
        dp = ndp;
    }

    ll ans = 0;

    for(int i = 0; i <= n; i++)
        ans = max(ans, dp[i]);


    cout << ans << "\n";
	
    return 0;
}


