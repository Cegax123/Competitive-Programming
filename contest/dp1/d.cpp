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

const int maxn = 10000;
const int ZERO = maxn+1;
const ll mod = 1e9+7;

ll sum(ll a, ll b) {
    ll ans = (a+b)%mod;
    return (ans+mod)%mod;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;

    int a[n+1];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
	
    int dp[n+1][ZERO+maxn+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; i++) {
        dp[i][ZERO+a[i]]++;
        dp[i][ZERO-a[i]]++;
        for(int j = -maxn; j <= maxn; j++) {
            if(j-a[i] >= -maxn) dp[i][ZERO+j] = sum(dp[i][ZERO+j], dp[i-1][ZERO+j-a[i]]);
            if(j+a[i] <= maxn) dp[i][ZERO+j] = sum(dp[i][ZERO+j], dp[i-1][ZERO+j+a[i]]);
        }
    }

    ll ans = 0; 

    for(int i = 1; i <= n; i++)
        ans = sum(ans, dp[i][ZERO]);

    cout << ans << "\n";

	return 0;
}

