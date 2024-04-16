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
    const int maxn = 2e5 + 5;
    const int mod = 1e9 + 7;

    int t, k; cin >> t >> k;

    int dp[maxn];
    dp[0] = 1;

    for(int i = 1; i < maxn; i++) {
        dp[i] = dp[i-1];
        if(i-k >= 0) dp[i] = (dp[i] + dp[i-k]) % mod;
    }

    for(int i = 1; i < maxn; i++) {
        dp[i] = (dp[i] + dp[i-1]) % mod;
    }

    while(t--) {
        int a, b; cin >> a >> b;
        int ans = dp[b] - dp[a-1];
        ans %= mod;

        if(ans < 0) ans += mod;

        cout << ans << "\n";
    }
	
    return 0;
}


