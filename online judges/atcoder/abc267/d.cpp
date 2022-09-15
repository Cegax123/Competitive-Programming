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
    ll a[n+1];
    a[0] = 0;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    const ll INF = (ll) 1e18;
    ll dp[n+1][n+1];

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = -INF;

    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + (ll) j * a[i]);
        }
    }

    ll ans = -INF;

    for(int i = 1; i <= n; i++)
        ans = max(ans, dp[i][m]);

    cout << ans << "\n";
	
    return 0;
}


