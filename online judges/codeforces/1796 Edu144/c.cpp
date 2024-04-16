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
    const int mod = 998244353;

    const int maxn = 50;

    ll f[maxn];
    f[0] = 1;

    for(int i = 1; i < maxn; i++)
        f[i] = (f[i-1] * i) % mod;

    ll ivf[maxn];

    ivf[maxn-1] = ex(f[maxn-1], mod-2, mod);

    for(int i = maxn-2; i >= 0; i--) 
        ivf[i] = (ivf[i+1] * (i+1)) %mod;

    auto comb = [&](int x, int y) {
        return (f[x] * (ivf[x-y] * ivf[y] % mod) ) %mod;
    };

    int t; cin >> t;
    while(t--) {
        ll l, r; cin >> l >> r;
        
        ll x = l, y = r;
        int p = 0;
        while(2 * x <= y) {
            p++;
            x *= 2;
        }

        if(p == 0) {
            cout << 1 << " ";
            cout << r-l+1 << "\n";
            continue;
        }

        ll sum[p+1];

        sum[0] = comb(p, 0);

        for(int j = 1; j <= p; j++) {
            sum[j] = (sum[j-1] + comb(p, j)) % mod;
        }

        ll p2 = 1;

        for(int i = 0; i < p; i++)
            p2 *= 2;
        
        ll p3 = 1;
        int q = 0;

        ll ans = 0;

        while(true) {
            if(p2 < 1 or l * p3 * p2 > r) break;

            ll tl = l, tr = r;
            while(tl < tr) {
                ll m = (tl + tr + 1ll) >> 1;
                if(m * p3 * p2 <= r) tl = m;
                else tr = m-1;
            }
            
            //cout << q << " " << tl << endl;
            ans = (ans + (comb(p, q) * ((ll) tl-l+1)) % mod) % mod;
            p3 *= 3;
            q++;
            p2 /= 2;
        }

        cout << p+1 << " ";
        cout << ans << "\n";
    }
	
    return 0;
}


