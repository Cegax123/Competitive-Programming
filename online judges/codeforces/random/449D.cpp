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
const ll mod = 1e9+7;

ll ex(ll a, ll b, ll c) {
	ll ans = 1;

	while(b > 0) {
		if(b&1) ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}

	return ans;
}

ll sum(ll a, ll b, ll c) {
    ll ans = (a+b)%c;
    return (ans+c)%c;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;

    vector<ll> dp(1 << m, 0);

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        dp[a]++;
    }

    for(int i = 0; i < m; ++i) {
        for(int mask = 0; mask < (1<<m); mask++) {
            if((mask & (1<<i))==0) dp[mask] += dp[mask|(1<<i)];                
        }
    }

    for(int mask = 0; mask < (1 << m); mask++)
        dp[mask] = sum(ex(2, dp[mask], mod),-1,mod);

    ll ans = dp[0];
    ll sub = 0;
    for(int i = 1; i < (1 << m); i++) {
        int cnt = 0;

        for(int j = 0; j < m; j++)
            if((i>>j)&1) cnt++;

        if(cnt&1) sub = sum(sub, dp[i], mod);
        else sub = sum(sub, -dp[i], mod);
    }

    ans = sum(ans, -sub, mod);

    cout << ans << "\n";
	    
	return 0;
}

