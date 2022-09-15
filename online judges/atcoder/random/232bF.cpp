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
    ll n, X, Y; cin >> n >> X >> Y;
    ll a[n], b[n];

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
        
	
    ll dp[1 << 18];
    const ll INF = (ll) 1e18;

    dp[0] = 0;

    for(int i = 1; i < (1 << n); i++)
        dp[i] = INF;

    auto f = [&] (int mask, int x) {
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            if((mask >> i)&1) continue;
            if(i < x) ans++;
        }
        return ans;
    };

    for(int mask = 0; mask < (1 << n); mask++) {
        int ind = __builtin_popcount(mask);
        for(int x = 0; x < n; x++) {
            if((mask >> x)&1) continue;
            ll add = abs(a[x] - b[ind]) * X + f(mask, x) * Y;
            int next_mask = mask | (1 << x);

            dp[next_mask] = min(dp[next_mask], dp[mask] + add);
        }
    }

    cout << dp[(1 << n)-1] << "\n";

    return 0;
}


