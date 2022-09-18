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
    const ll mod = 998244353;

    ll n, m; cin >> n >> m;

    auto mul = [&](ll a, ll b) {
        return (a*b)%mod;
    };

    auto sum = [&](ll a, ll b) {
        return (a+b)%mod;
    };


    auto f = [&](ll x, ll y) {
        if(x == 0 or y == 0) return 0ll;

        ll odd = (x+1)/2, even = x/2;
        ll cnt_o = (y+1)/2, cnt_e = y/2;
        ll ans = mul(mul(cnt_o, cnt_o), odd) + mul(even, mul(cnt_e, cnt_e+1));
        ll add1 = mul(mul(m, odd), mul(odd-1, cnt_o));
        ll add2 = mul(mul(m, even), mul(even, cnt_e));

        return sum(ans, sum(add1, add2));
    };
    int q; cin >> q;
    while(q--) {
        int a, c, b, d; cin >> a >> c >> b >> d;
        ll ans = f(c, d) - f(c, b-1) - f(a-1, d) + f(a-1, b-1);
        ans %= mod;
        if(ans < 0) ans += mod;

        cout << ans << "\n";
    }
	
    return 0;
}


