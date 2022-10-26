// SOLVED

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

const int m = 20;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi cnt(1 << m, 0), dp(1 << m, 0);

        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            cnt[a]++;
        }

        for(int i = 0; i < (1 << m); i++)
            dp[i] = cnt[i];
                            
        for(int i = 0; i < m; i++) 
            for(int mask = 0; mask < (1 << m); mask++) 
                if(mask & (1 << i)) dp[mask] += dp[mask^(1 << i)];

        ll ans = 0;
        for(int i = 0; i < (1 << m); ++i) 
            ans += (ll) (cnt[i] * (cnt[i]-1ll))/2ll + cnt[i] * (dp[i]-cnt[i]);

        cout << ans << "\n";
    }

	return 0;
}


