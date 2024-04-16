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

const int mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int a[n];

        for(int i = 0; i < n; i++) cin >> a[i];

        ll dp[n];
        dp[0] = max(a[0], 0);
        for(int i = 1; i < n; i++) {
            dp[i] = max({0LL + a[i], dp[i-1] + a[i], 0LL});
        }

        ll ans = 0;
        for(int i = 0; i < n; i++) ans = max(ans, dp[i]);

        int m = ans % mod;

        for(int i = 0; i < k; i++) {
            m = m * 2 % mod;
        }

        int sum = (m - ans) % mod;

        for(int i = 0; i < n; i++) {
            sum = (sum + a[i]) % mod;
        }
        if(sum < 0) sum += mod;
        
        cout << sum << "\n";
    }

	
    return 0;
}


