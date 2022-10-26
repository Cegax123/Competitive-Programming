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
    int n, s, e; cin >> n >> s >> e;
    ll x[n+1], a[n+1], b[n+1], c[n+1], d[n+1];
 
    for(int i = 1; i <= n; i++) cin >> x[i];
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) cin >> d[i];
 
    ll dp[n+5][n+5];
    const ll INF = (ll) 1e18;
 
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = INF;
 
    dp[0][0] = 0;
	
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            ll ans = INF;
            if(i == s) {
                // new component
                ans = min(ans, dp[i-1][j-1] - x[s] + d[s]);
 
                // add to component
                ans = min(ans, dp[i-1][j] + x[s] + c[s]);
            }
            else if(i == e) {
                // new component
                ans = min(ans, dp[i-1][j-1] - x[e] + b[e]);
 
                // add to component
                ans = min(ans, dp[i-1][j] + x[e] + a[e]);
            }
            else {
                // new component
 
                int places = j - (i > s) - (i > e);
                if(places >= 1)
                    ans = min(ans, dp[i-1][j-1] - 2 * x[i] + b[i] + d[i]);
 
                // end in component
 
                places = j - (i > e);
 
                if(places >= 1)
                    ans = min(ans, dp[i-1][j] + a[i] + d[i]);
 
                // start in component
                
                places = j - (i > s);
 
                if(places >= 1) 
                    ans = min(ans, dp[i-1][j] + b[i] + c[i]);
 
                // merge component
                ans = min(ans, dp[i-1][j+1] + 2 * x[i] + a[i] + c[i]);
            }
 
            dp[i][j] = ans;
 
        }
    }
 
    //for(int i = 1; i <= 3; i++) {
        //for(int j = 1; j <= i; j++) {
            //cout << dp[i][j] << " ";
        //}
        //cout << endl;
    //}
 
    cout << dp[n][1] << "\n";
 
    return 0;
}

