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
    int a[n+1];

	for(int i = 1; i <= n; i++) cin >> a[i];

    ll dp[n+1];
    for(int i = 1; i <= n; i++) dp[i] = (ll) -1e18;

    dp[1] = a[1];

    for(int i = 2; i <= n; i++) {
        dp[i] = a[i];
        for(int j = 1; j <= i-1; j++) {
            dp[i] = max(dp[i], dp[i-j] + dp[j]);
        }
    }

    cout << dp[n] << "\n";

    return 0;
}


