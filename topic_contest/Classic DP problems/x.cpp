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

    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    ll sum[n];
    sum[0] = a[0];
    for(int i = 1; i < n; i++) sum[i] = sum[i-1] + a[i];

    const ll INF = (ll) 1e18;

    ll dp[n][n];
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) dp[i][j] = INF;
    for(int i = 0; i < n; i++) dp[i][i] = 0;

    for(int len = 2; len <= n; len++) {
        for(int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;

            for(int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum[j] - (i ? sum[i-1] : 0));
            }
        }
    }

    cout << dp[0][n-1] << "\n";
	
    return 0;
}


