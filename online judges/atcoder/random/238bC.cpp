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

const ll mod = 998244353;

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
	ll x; cin >> x;
    ll p = 10;
    ll ans = 0;

    while(p-1 < x) {
        ll f = p-p/10ll;
        ll sum = (f%mod) * ((f+1)%mod);
        sum %= mod;
        sum = sum*ex(2, mod-2, mod)%mod;

        ans = (ans+sum)%mod;
        p *= 10ll;
    }

    p /= 10ll;

    ll f = (x-p+1);
    ll sum = (f%mod) * ((f+1)%mod);
    sum %= mod;
    sum = sum*ex(2, mod-2, mod)%mod;

    ans = (ans+sum)%mod;

    cout << ans << "\n";
	
	return 0;
}

