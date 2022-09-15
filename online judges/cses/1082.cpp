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

ll ex(ll a, ll b, ll c) {
	ll ans = 1;

	while(b > 0) {
		if(b&1) ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}

	return ans;
}

ll mul(ll a, ll b, ll c) {
    return a*b%c;
}

ll sum(ll a, ll b, ll c) {
    ll ans = (a+b)%c;
    return (ans+c)%c;
}

ll inv2 = ex(2, mod-2, mod);

ll tri(ll a, ll c) {
    if(a <= 0) return 0;

    ll num = mul(a%c, (a+1)%c, c);

    return mul(num, inv2, c);
}

ll interval_sum(ll l, ll r, ll c) {
    return sum(tri(r, c), -tri(l-1, c), c);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
    ll n; cin >> n;
    ll sqn = 1;

    while(sqn * sqn <= n) 
        sqn++;

    ll ans = 0;
    for(ll i = 1; i * i <= n; i++) {
        ll q = n/i;

        if(q > sqn)
            ans = sum(ans, i * q, mod);
    }

    for(ll q = 1; q <= sqn; q++) {
        ll l = n/(q+1ll), r = n/q;
        l++;

        if(l <= r) ans = sum(mul(interval_sum(l, r, mod), q, mod), ans, mod);
    }

    cout << ans << "\n";

	return 0;
}

