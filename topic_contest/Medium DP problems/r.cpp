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
    int n; cin >> n;
    vi a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    a.pb(0);

    const int INF = 1e9;

    int dp[n+1][n+1][2];

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j][0] = dp[i][j][1] = INF;

    dp[0][0][0] = dp[0][0][1] = 0;
    dp[1][1][1] = max(0, a[1]-(a[0]-1));
    dp[1][0][0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            dp[i][j][0] = min(dp[i-1][j][0], dp[i-1][j][1]);

            if(i >= 2 and j >= 1) {
                int d1 = max(0, a[i]-(a[i-1]-1)), d2 = max(0, a[i-2]-(a[i-1]-1));
                dp[i][j][1] = min(dp[i][j][1], d1 + d2 + dp[i-2][j-1][0]);

                if(i >= 3) {
                    int d3 = max(0, min(a[i-2], a[i-3]-1) -(a[i-1]-1));
                    dp[i][j][1] = min(dp[i][j][1], d1 + d3 + dp[i-2][j-1][1]);
                }
            }
        }
    }

    vi ans(n, INF);

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= (n+1)/2; j++) {
            //cout << dp[i][j][0] << " " << dp[i][j][1] << "\n";

            ans[j] = min({ans[j], dp[i][j][0], dp[i][j][1]});
        }
    }

    for(int i = 1; i <= (n+1)/2; i++)
        cout << ans[i] << " ";
	
    return 0;
}


