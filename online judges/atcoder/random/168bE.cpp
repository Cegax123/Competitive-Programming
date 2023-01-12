#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    const ll mod = 1000000007;
    const int maxn = 4e5 + 10;
    ll p2[maxn];

    p2[0] = 1;

    for(int i = 1; i < maxn; i++)
        p2[i] = (p2[i-1] * 2) % mod;

    int n; cin >> n;

    ll cnt00 = 0;
    ll cnt10 = 0, cnt01 = 0;

    map<ii, int> cnt;
    set<ii> s;

    for(int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        ll g = __gcd(abs(a), abs(b));
        a /= g; b /= g;
        if(b < 0) a *= -1, b *= -1;

        if(a == 0 and b == 0) cnt00++;
        else if(a == 0) cnt01++;
        else if(b == 0) cnt10++;
        else {
            cnt[{a,b}]++;
            s.insert({a, b});
        }
    }

    auto mul = [&](ll x, ll y) {
        return x * y % mod;
    };

    ll ans = ((p2[cnt10] + p2[cnt01] - 1) % mod + mod) % mod;

    for(auto e : cnt) {
        ii pa = e.first;
        if(!s.count(pa)) continue;
        ii o = {-pa.second, pa.first};
        if(o.second < 0) o.first = -o.first, o.second = -o.second;

        ans = mul(ans, ((p2[e.second]+p2[cnt[o]]-1)%mod+mod)%mod);

        s.erase(pa);
        if(s.count(o)) s.erase(o);
    }

    ans = (ans + cnt00) % mod;
    ans--;

    if(ans < 0) ans += mod;

    cout << ans << "\n";
	
    return 0;
}


