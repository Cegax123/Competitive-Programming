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

const ll mod = 1e9+7;

ll sum(ll a, ll b, ll c) {
    ll ans = (a+b)%c;
    return (ans+c)%c;
}

ll ex(ll a, ll b, ll c) {
	ll ans = 1;

	while(b > 0) {
		if(b&1) ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;

    ll dp[1 << m];
    memset(dp, 0, sizeof(dp));

    const int MASK = (1 << m)-1;

    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        int a = 0;

        for(int j = 0; j < k; j++) {
            int c; cin >> c;
            c--;
            a |= (1 << c);
        }

        a ^= MASK;
        dp[a]++;
    }
	    
    for(int i = 0; i < m; i++) {
        for(int mask = 0; mask < (1 << m); mask++) {
            if((mask & (1 << i))==0) dp[mask] = sum(dp[mask], dp[mask|(1<<i)], mod);
        }
    }

    int b[1 << m];
    for(int mask = 0; mask < (1 << m); mask++) {
        b[mask] = 0;
        for(int j = 0; j < m; j++) {
            if((mask>>j)&1) b[mask]++;
        }
        dp[mask] = sum(ex(2, dp[mask], mod), -1, mod);
        if(b[mask]&1) dp[mask] = mod-dp[mask];
    }

    for(int i = 0; i < m; i++) 
        for(int mask = 0; mask < (1 << m); mask++) 
            if((mask & (1 << i))==0) dp[mask] = sum(dp[mask], dp[mask|(1<<i)], mod);

    int x = 0;

    int ans = dp[x];
    if(b[x]&1) ans = (mod-ans)%mod;

    cout << ans << "\n";
	
	
	return 0;
}


