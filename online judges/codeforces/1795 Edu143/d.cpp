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

    const int maxn = 3e5 + 5;
    const ll mod = 998244353;

    auto mul = [&](ll a, ll b) {
        return a * b % mod;
    };

    ll f[maxn];
    f[0] = 1;

    for(int i = 1; i < maxn; i++)
        f[i] = mul(f[i-1], i);

    ll ivf[maxn];
    ivf[maxn-1] = ex(f[maxn-1], mod-2, mod);

    for(int i = maxn-2; i >= 0; i--) {
        ivf[i] = mul(ivf[i+1], i+1);
    }

    auto comb = [&](ll m, ll n) {
        return mul(f[m], mul(ivf[n], ivf[m-n]));
    };

    int n; cin >> n;

    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = comb(n/3, n/6);

    for(int i = 0; i < n; i += 3) {
        vi c;
        c.pb(a[i]);
        c.pb(a[i+1]);
        c.pb(a[i+2]);

        sort(all(c));

        if(c[2] == c[0]) {
            ans = mul(ans, 3);
        }
        else if(c[0] == c[1]) {
            ans = mul(ans, 2);
        }
    }

    cout << ans << "\n";
	
    return 0;
}


