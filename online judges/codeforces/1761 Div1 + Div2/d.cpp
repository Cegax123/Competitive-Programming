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

const ll mod = (ll) 1e9 + 7;

ll ex(ll a, ll b, ll c) {
	ll ans = 1;

	while(b > 0) {
		if(b&1) ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}

	return ans;
}

const int maxn = 2e6 + 5;
ll fact[maxn];
ll ifact[maxn];
ll p3[maxn];

ll mul(ll a, ll b) {
    return a * b % mod;
}

ll comb(ll n, ll k) {
    return mul(fact[n], mul(ifact[k], ifact[n-k]));
}

ll sum(ll a, ll b) {
    return (a+b)%mod;
}

ll f(ll n, ll k) {
    if(k == 0) return p3[n];
    ll ans = 0;
    for(int i = 1; i <= k and n-k-i >= 0; i++) {
        ll curr = mul(p3[k-i], p3[n-k-i]);
        curr = mul(curr, mul(comb(k-1, i-1), comb(n-k, i)));
        ans = sum(ans, curr);
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fact[0] = 1;
    for(int i = 1; i < maxn; i++) {
        fact[i] = fact[i-1] * i % mod;
    }

    ifact[maxn-1] = ex(fact[maxn-1], mod-2, mod);

    for(int i = maxn-2; i >= 0; i--) {
        ifact[i] = ifact[i+1] * (i+1) % mod;
    }
    
    p3[0] = 1;
    for(int i = 1; i < maxn; i++)
        p3[i] = p3[i-1] * 3 % mod;

    int n, k; cin >> n >> k;
    ll ans = f(n+1, k) - 2 * f(n, k);
    ans %= mod;
    if(ans < 0) ans += mod;

    cout << ans << "\n";
	
    return 0;
}


